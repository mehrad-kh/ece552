#include <stdio.h>
#define blcksize 64  //cache block size
#define test_param 1 //next line should work for test_param = 1 and fail test_param = 2 on the array accesses(tediously)

int main(){

char a[1000000]; // each char takes 1 byte in memory

char b;
int i;

//accesses that are made with each iterations of the loop are noted

for(i = 0; i < 1000000; i += blcksize*test_param) //three accesses to i 
	b = a[i]; //one access to b, one access to i, *one access to a[i]*

}

/*The array access is 1 out of 6 total accesses in our for loop. Therefore, for test_const = 2, we expected to have 1/6 = 16.7% cache  misses. For test_const = 1,  cache miss was expected to be negligible. Our results matches our expectations with 15.46% miss rate for test_const = 2 and 0.02% miss rate for test const = 1
*/
