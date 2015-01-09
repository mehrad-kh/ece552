#include <stdio.h>


int main (void)
{
	int a=1;
	int b = 0;
	int i;
	for (i = 0; i < 1000000; i++)
	{
		__asm__( "lw $2,16($30);"
		"addu $6,$0,$0;"
		"sw $2,20($30);"
		"addu $6,$0,$6;"
		"sw $6,20($30);"
		"addu $6,$0,$6;"
		"lw $2,16($30);"
		"lw $3,16($30);"
		"addu $6,$0,$0;"
		"addu $2,$2,$3;"
		"sw $2,20($30);");
	}

	return 0;
}
/*Below is the snippet of generated assembly codes belongs to the for loop. In a 5 stage pipeline, 
if we have an instruction in the pipeline then only the next two instructions coming afterward 
are potential to cause hazard, if they are dependant to that instruction. 
There are two cases in a five stage piplines that leads to hazard.

case 1) If INST2 is dependent on INST1 regardless of whether INST3 is dependant on INST it casues 2 cycles stall. 
In the case that INST3 is dependant on INST1 the stall will be propagated and there be no stalls for this dependency.

INST3       INST2 ----------->INST1   
                (dependency)

case 2) If INST3 is dependant on INST1 and INST2 is not dependant INST1 then there will be a one cycle stall. 

INST3       INST2              INST1
    |                        ^
    |_ _ _ _ _ _ _ _ _ _ _ _ |
           (dependency)

snippet of generated assembly codes of the for loop:
INST1) lw $2,24($30)   
INST2) lui $3,15 
INST3) ori $3,$3,16959 
INST4) slt $2,$3,$2 
INST5) beq $2,$0,400268 <main+0x78> 
INST6) j 4002e8 <main+0xf8> 
INST7) lw $2,16($30) 
INST8) addu $6,$0,$0 
INST9) sw $2,20($30) 
INST10) addu $6,$0,$6 
INST11) sw $6,20($30)  
INST12) addu $6,$0,$6 
INST13) lw $2,16($30) 
INST14) lw $3,16($30)   
INST15) addu $6,$0,$0 
INST16) addu $2,$2,$3 
INST17) sw $2,20($30) 
INST18) lw $3,24($30) 
INST19) addiu $2,$3,1  
INST20) addu $3,$0,$2    
INST21) sw $3,24($30)  
INST22) j 400238 <main+0x48> 

RAW dependencies potnetial to cause hazard in the above code:
1) INST3 is dependant on INST2 ----> 2 cycles stall
2) INST4 is dependant on INST3 ----> 2 cycles stall
3) INST5 is dependant on INST4 ----> 2 cycles stall
4) INST9 is depdndant on INST7 -----> 1 cycle stall
5) INST10 is dependant on INST8 ----> no stall. the stall form the previous instruction will be propagated
6) INST11 is dependant on INST10 ----> 2 cycles stall
7) INST12 is dependant on INST10 -----> no stall. the stall form the previous instruction will be propagated
8) INST16 is dependant on INST INST14 -----> 1 cycle stall
9) INST17 is dependant on INST16 -----> 2 cycles stall
10) INST19 is dependant on INST18 -----> 2 cycles stall
11) INST20 is dependant on INST19 -----> 2 cycles stall
12) INST21 is dependant on INST20 -----> 2 cycles stall  

As we can see from above there are 8 hazards that cause 2 cycles stall and 2 hazards that cause one cycle stall. 
Given that 'for' loop is executed 1000000 times number of two cycles hazards and one cycle hazards should be around 8000000 and 2000000 respectively.  

q1_one_cycle_stall_count      2000081 # total number of one cycle stalls 
q1_two_cycle_stall_count      8000869 # total number of two cycle stalls 

These outputs match with our expectations.*/