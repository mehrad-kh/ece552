#include "predictor.h"
#include <math.h>
#include <bitset>
#include <functional>

/////////////////////////////////////////////////////////////
// 2bitsat
/////////////////////////////////////////////////////////////
#define TWOBITSAT_SIZE 4096
#define PC_MASK 0x00000fff
#define TWOBITSAT_INDEX(PC) PC & PC_MASK
short * twobitsat;

void InitPredictor_2bitsat() 
{
    twobitsat = (short *)malloc (TWOBITSAT_SIZE * sizeof(short));
    //initialize to weakly taken;
    int i;
    for (i = 0; i < TWOBITSAT_SIZE; i++)
    {
        twobitsat[i] = 1;  
    } 
}

bool GetPrediction_2bitsat(UINT32 PC) 
{
  int index = TWOBITSAT_INDEX(PC);
  short pred_state = twobitsat[index];
  if(pred_state >= 2)    
      return TAKEN;
  else
      return NOT_TAKEN;
   
}

void UpdatePredictor_2bitsat(UINT32 PC, bool resolveDir, bool predDir, UINT32 branchTarget) 
{
    int index = TWOBITSAT_INDEX(PC);
    short pred_state = twobitsat[index];
    if(resolveDir == TAKEN)
    {
        if(pred_state < 3)
        {
            twobitsat[index]++;    
        }
    }
    else
    {
        if(pred_state > 0)
        {
            twobitsat[index]--;    
        }
    }

}

/////////////////////////////////////////////////////////////
// 2level
/////////////////////////////////////////////////////////////
#define BHT_SIZE 512
#define PHT_NUMBERS  8
#define PHT_SIZE 64
#define BHT_MASK 0x00000ff8
#define PHT_MASK 0x00000007
#define ENTRY_MASK 0X003f

#define BHT_INDEX(PC) (PC & BHT_MASK) >> 3
#define PHT_ID(PC) (PC & PHT_MASK)
#define PHT_INDEX(val) (val & ENTRY_MASK)
short * BHT;
short ** PHTs;

void InitPredictor_2level() 
{
    //512-entries table of local history register (BHT) 6 history per bit
   BHT = (short *)malloc(BHT_SIZE * sizeof(short));
    int i;
    for (i = 0; i < BHT_SIZE; i++)
    {
        BHT[i] = 0;
    }

    PHTs = (short **) malloc(PHT_NUMBERS * sizeof(short *));
    for (i = 0; i < PHT_NUMBERS; i++)
    {
        PHTs[i] = (short *)malloc(PHT_SIZE * sizeof(short));
        // Initialize each entry in PHTs to 1 (Weak Not Taken)
        int j;
        for (j = 0; j < PHT_SIZE; j++)
        {
            PHTs[i][j] = 1;  
        }
    }
}

bool GetPrediction_2level(UINT32 PC) 
{
    int BHT_index = BHT_INDEX(PC);
    int PHT_ID = PHT_ID(PC);
    int PHT_index = PHT_INDEX(BHT[BHT_index]);
    short pred_state = PHTs[PHT_ID][PHT_index];
    if (pred_state >= 2)
        return TAKEN;
    else
        return NOT_TAKEN;

     // return TAKEN;
}

void UpdatePredictor_2level(UINT32 PC, bool resolveDir, bool predDir, UINT32 branchTarget) 
{
    int BHT_index = BHT_INDEX(PC);
    int PHT_ID = PHT_ID(PC);
    int PHT_index = PHT_INDEX(BHT[BHT_index]);

    // Update PHT 
    short pred_state = PHTs[PHT_ID][PHT_index];
    if(resolveDir == TAKEN)
    {
        if(pred_state < 3)
        {
            PHTs[PHT_ID][PHT_index]++;    
        }
    }
    else
    {
        if(pred_state > 0)
        {
            PHTs[PHT_ID][PHT_index]--;    
        }
    }

    // Update BHT
    if(resolveDir == TAKEN)
        BHT[BHT_index] = (BHT[BHT_index] << 1) | TAKEN;
    else
        BHT[BHT_index] = (BHT[BHT_index] << 1);

}

/////////////////////////////////////////////////////////////
// openend
/////////////////////////////////////////////////////////////

class saturating_counter
{
public:
  short counter;
  short saturated_positive;
  short saturated_negative;

  void increment(int value)
  {
    if(counter + value < saturated_positive)
      counter += value;
    else
      counter = saturated_positive;
  }

  void decrement(int value)
  {
    if(counter - value > saturated_negative)
      counter -= value;
    else
      counter = saturated_negative;
  }
};


#define PHT_NUM 14
#define PREDICTOR_TABLE_SIZE 2048
saturating_counter ** predictor_tables;
std::bitset<PREDICTOR_TABLE_SIZE> tag_bit;

//Global Histroy Register
#define GHR_LENGTH 3360


int L[17] = {0, 3, 5, 8, 12, 19, 31, 49, 75, 125, 200, 320, 512, 820, 1312, 2100, 3360};
int history_length[PHT_NUM];



saturating_counter AC;  //9 bit saturating ailiasing counter
saturating_counter TC; //7 bit saturating ailiasing counter

int theta; // value between 0 to 31
#define MAX_THETA 31

long long phr; // path history register

#define ghr_size 6
long long ghr[ghr_size]; 

int GetIndexOfTable(UINT32 PC, int PHT_ID)
{
  // 33 bits of this input is used as 3 11-bit input for the XOR
  long long input;  
  int history_len = history_length[PHT_ID];
  int path_len = min(16, history_len);

  // for calculating the index we use history_len bits from ghr, path_len bits from phr and at least
  // 8 bits of PC and at most 20 bits. We need to calculate an 11 bit index which is an output of 3 entries XOR gates.
  // Therefor we will have 33 bits as input on our XOR gate. 

  // We check if need to ignore some bits in phr or ghr in order to include at least 8 bits form PC
  int pc_bits_len = 33 - history_len - path_len;
  if(pc_bits_len > 20)
    pc_bits_len = 20;

  if(pc_bits_len < 8)
  {
    // we need to ignore some bits in phr and ghr
    int fills[34];
    int i;
    for(i = 0; i < 33; i++)
      fills[i] =  ((i * (8 + history_len + path_len - 1)) / (32));
    fills[33] = 8 + history_len + path_len;

    input = 0;
    // ghr bits
    long long ghr_chunk = ghr[0];
    ghr_chunk >>= fills[0];
    input = (ghr_chunk & 1);
    int chunk_index = 0;

    int shift; // value to shift ghr_chunk
    for (i = 1; fills[i] < history_len; i++)
    {

      if ((fills[i] & 0xffc0) == (fills[i - 1] & 0xffc0))
      {
        shift = fills[i] - fills[i - 1];
      }
      else
      {
        ghr_chunk = ghr[chunk_index];
        chunk_index++;
        shift = fills[i] & 63;
      }
      input = (input << 1);
      ghr_chunk = ghr_chunk >> shift;
      input ^= (ghr_chunk & 1);
    }

    //pc bits
    for( ; fills[i] < history_len + 8; i++)
    {
      shift = fills[i] - history_len;
      input = (input << 1);
      input ^= ((PC >> shift) & 1);
    }

    //phr bits
    for (; fills[i] < path_len + history_len + 8; i++)
    {
      shift = fills[i] - (history_len + 8);
      input = (input << 1);
      input ^= ((phr >> shift) & 1);
    }
  } 

  else
  {
    // concatinate all the bits and store it in input
    input = ((ghr[0] & ((1 << history_len) - 1)) << (pc_bits_len + path_len)) + 
    ((PC & ((1 << pc_bits_len) - 1)) << path_len) + 
    ((phr & ((1 << path_len) - 1)));
  }

  // now we have the 33 bits input ready to be XORed. 

  int identifier = (PHT_ID & 3) + 1;


  long long index = input & ((1 << 11) - 1);
  int i;
  for (i = 1; i < 3; i++)
    {
      input = input >> 11;

      index ^=
        ((input & ((1 << 11) - 1)) >> identifier) ^((input & ((1 << identifier) - 1)) << ((11 - identifier)));

      identifier = (identifier + 1) % 11;
    }

  return ((int) index);

}




void InitPredictor_openend() 
{
    int i,j;
   
    // initializing predictor tables and setting all counters to zero
    predictor_tables = (saturating_counter **)malloc(PHT_NUM * sizeof(saturating_counter *));
    for (i = 0; i < PHT_NUM; i++)
    {
        predictor_tables[i] = (saturating_counter *)malloc(PREDICTOR_TABLE_SIZE * sizeof(saturating_counter));
        for(j = 0; j < PREDICTOR_TABLE_SIZE; j++)
        {
            predictor_tables[i][j].counter = 0;
            if(i==0 || i == 1)
            {
                // T0 and T1 are 5 bits saturating counters
                predictor_tables[i][j].saturated_positive = 15;
                predictor_tables[i][j].saturated_negative = -16;
            }
            else
            {
                // other tables are 4 bits saturating counters
                predictor_tables[i][j].saturated_positive = 7;
                predictor_tables[i][j].saturated_negative = -8;
            }
        }
    }

    // set the tag bit to zero
    tag_bit.set(0);


    AC.counter = 0;
    AC.saturated_positive = 255;
    AC.saturated_negative = -256;

    TC.counter = 0;
    TC.saturated_positive = 63;
    TC.saturated_negative = -64;

    theta = PHT_NUM;

    for(i = 0; i < PHT_NUM; i++)
    {
      history_length[i] = L[i];
    }

    phr = 0;
    for (i = 0 ; i < ghr_size; i++)
      ghr[i] = 0;
   
}

bool GetPrediction_openend(UINT32 PC) 
{
  
  int S = PHT_NUM / 2;
  int i;
  int index[PHT_NUM];

  for(i = 0; i < PHT_NUM; i++)
  {
     index[i] = GetIndexOfTable(PC, i);
     S += predictor_tables[i][index[i]].counter;
  }

  if(S >= 0)
      return TAKEN;

  return NOT_TAKEN;
}


void UpdatePredictor_openend(UINT32 PC, bool resolveDir, bool predDir, UINT32 branchTarget) 
{
  int S = PHT_NUM / 2;
  int i;
  int index[PHT_NUM];
  for(i = 0; i < PHT_NUM; i++)
  {
      index[i] = GetIndexOfTable(PC, i);
      S += predictor_tables[i][index[i]].counter;
  }


  //dynamic threshhold fitting
  if(resolveDir != predDir)
  {
      TC.increment(1);
      if(TC.counter == TC.saturated_positive)
      {
          if(theta < MAX_THETA)
          {
            theta++;
            TC.counter = 0; 
          } 
      }
  }
  else if((S >= -theta) && (S < theta))
  {
    TC.decrement(1);
    if(TC.counter == TC.saturated_negative)
    {
      if(theta > 0)
      {
        theta--;
        TC.counter = 0;
      }
    }
  }
 

  //Updating Predictor Tables
  if(resolveDir != predDir || ((S < theta) && (S >= -theta)))
  {
      for(i = 0; i < PHT_NUM; i++)
      {
          if(resolveDir)
              predictor_tables[i][index[i]].increment(1);
          else
              predictor_tables[i][index[i]].decrement(1);
      }
  }



  // Dynamic History Length Fitting
  if(resolveDir != predDir)
  {
      
      if((PC & 1) == (int)tag_bit[index[PHT_NUM -1]])
          AC.increment(1);
      else
          AC.decrement(4);

      if(AC.counter == AC.saturated_positive)
      {
         history_length[2] = L[PHT_NUM]; 
         history_length[4] = L[PHT_NUM + 1]; 
         history_length[6] = L[PHT_NUM + 2]; 
      }
      if(AC.counter == AC.saturated_negative)
      {
         history_length[2] = L[2]; 
         history_length[4] = L[4]; 
         history_length[6] = L[6]; 
      }
  }

  tag_bit.set(index[PHT_NUM -1], (PC & 1));


  // updating ghr
  for(i = ghr_size; i > 0; i--)
  {
    ghr[i] = (ghr[i] << 1) + (ghr[i -1] < 0);
  }
  ghr[0] = ghr[0] << 1;

  if(resolveDir)
    ghr[0]++;

  // updating phr
  phr = (phr << 1) | (PC & 1);
}


