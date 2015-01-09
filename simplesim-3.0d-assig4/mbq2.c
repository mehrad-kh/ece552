#include <stdio.h>
#define blck_size 64 
#define test_param 1 //For test_const = 1 stride should work (the if and the else will become the same thing and acceses happen at a constant "stride"). In contrary, for any value greater than 1(used value: 2), stride prefetcher would fail(since then the if and the else would increment i differently and "stride" would be alternating).

int main(){

char a[1000000];
int i = 0, sum = 0;
while(i < 1000000){ 
	sum += a[i]; // 2 accesses to sum, 1 access to i, *1 access to a[i] (the miss)*
	
	if(i%2 == 0) // 2 accesses to i
		i += (blck_size+1);   // 2 access to i(on average between this line and the else)
	else
		i += (test_const*blck_size + 1);
}

}

/*The array access is 1 out of 8 total accesses in our for loop. Therefore, for test_const = 2, we expected to have 1/8 = 12.5% cache  misses. For test_const = 1,  cache miss was expected to be negligible. Our results matches our expectations with 11.98% miss rate for test_const = 2 and 0.02% miss rate for test const = 1
*/
