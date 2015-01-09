#include <stdio.h>
#define blcksize 64  //cache block size
#define test_param 1 //for test_param = 1 the first loop will run which uses pattern "test_pattern". Inthis case our prefetcher should recongnize the pattern and preform. For test_param != 1, there will be no particular pattern in accesses and open ended prefetcher should fail

int main(){
char a[1000000];//for this micro-benchmark we examine the performance of our prefetcher for one CZone(a.k.a: this size array is enough) 
int b;

int i;
int test_pattern[] = {1,2 ,4,2,5}; // random but repeating pattern
int j = 0; 

if(test_param == 1)
	for (i =0; i < 1000000; i++, j = (j+1)%5){ // 2 accesses to j, 3 accesses to i
		b += a[i];  // 1 access to i, 2 accesses to b, *1 access to a[i]*
		i +=  test_pattern[j]*blcksize; // 2 accesses to i , 1 access to j, 1 access to test_pattern 
	}
else
	for (i =0; i < 1000000; i++){//3 accesses to i
		b += a[i]; // 1 access to i, 2 accesses to b, *1 access to a[i]*
		i +=  rand(5)*blcksize;
		//dumby operation to have equal accesses to the first for loop
		j = (j+ test_pattern[j]) % 5 ;
		
	}


}

/*The array access is 1 out of 13 total accesses in our for loop. Therefore, for test_const = 2, we expected to have 1/13 = 7.6% cache  misses. For test_const = 1,  cache miss was expected to be much lower than 7.6%. Our results matches our expectations with 7.42% miss rate for test_const = 2 and 2.01% miss rate for test const = 1
*/
