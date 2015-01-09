//microbenchmark for 2-level predictor
//LAB2 ECE552

#include<stdio.h>

int main(){
int a[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
int i,j ,b = 0;
	for (i = j = 0 ; i < 10000; i++){
		if(a[j])
			b++;
		j= i % 20;
	}
printf("%d",b);


return 0;
}
/*
Following are the generic and actual snippets of the for loop of the code. 

For the IF BRANCH: 1: it always write in one specific table out of eight tables in the second level of the 2-level predictor. 
		   2: Since there is no other branch in radius of 8 instructions of the IF BRANCH, there will be no aliasing in the first level of the 2-level predictor and IF BRANCH is the only branch that updates the 6-bit history in its mapping to the first level. The history will be TTTTTT 14 times out of 20( The else possibilities for the history are TTTTTN, TTTTNT, TTTNTT, TTNTTT, TNTTTT, NTTTTT these map to a location in second level which will always have a STRONGLY TAKEN state and the branch will always be taken therefore no missprediction here). For when history bits are in TTTTTT state, 13 out of 14 times the branch is taken so the coresponding 2-bit saturated in second level will be kept in STRONGLY TAKEN state. But 1 out of 14 times the branch will be NOT TAKEN and the 2-bit saturated is in STRONGLY TAKEN STATE thereforethis is our *ONLY MISPREDICTION*. Then the 2- bit sat will enter weakly taken and the branch will be taken again for the next 13 times.

FOR the FOR BRANCH: it will always be taken therefore no missprediction here.

EXPECTATION: we have 20000(2 times the size of the for loop) branch instructions which 1/(6+14+20)= 1/40 of them are MISS PREDICTED (expecting 500 miss predictions). 

SIMULATION RESULTS: 584 miss predictions. 

RESULT JUSTIFICATION: The code was run with the size of the for loop being 1000, thus expecting 50 miss predictions. However, the number of miss predictions calculated was 133(also off by 84). Therefore, its safe to assume these misspredictions are for the warm up stage of the predictor. 

GREAT SUCCESS :D

*/

//*********************************FOLLOWING IS THE SNIPPET OF THE GENERIC ASSEMBLY CODE**********************************

/*
.L4:   ---------------------------------------------------->(begining of the FOR loop)
	movl	-8(%rbp), %eax
	cltq
	movl	-96(%rbp,%rax,4), %eax
	testl	%eax, %eax
	je	.L3  --------------------------------------> IF BRANCH, 5% miss prediction in branch predictor
	addl	$1, -12(%rbp)
.L3:
	movl	-4(%rbp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -8(%rbp)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$9999, -4(%rbp)
	jle	.L4      ---------------------------------->(end of the FOR loop) FOR BRANCH, 0% miss prediction in branch predictor 
*/

//******************************** FOLLOWING IS THE SNIPPET OF THE ACTUAL ASSEMBLY CODE*************************************

/*
  4005ae:	8b 45 f8             	mov    -0x8(%rbp),%eax
  4005b1:	89 45 fc             	mov    %eax,-0x4(%rbp)
  4005b4:	eb 3e                	jmp    4005f4 <main+0xe8>
  4005b6:	8b 45 f8             	mov    -0x8(%rbp),%eax
  4005b9:	48 98                	cltq   
  4005bb:	8b 44 85 a0          	mov    -0x60(%rbp,%rax,4),%eax
  4005bf:	85 c0                	test   %eax,%eax
  4005c1:	74 04                	je     4005c7 <main+0xbb>
  4005c3:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
  4005c7:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  4005ca:	ba 67 66 66 66       	mov    $0x66666667,%edx
  4005cf:	89 c8                	mov    %ecx,%eax
  4005d1:	f7 ea                	imul   %edx
  4005d3:	c1 fa 03             	sar    $0x3,%edx
  4005d6:	89 c8                	mov    %ecx,%eax
  4005d8:	c1 f8 1f             	sar    $0x1f,%eax
  4005db:	29 c2                	sub    %eax,%edx
  4005dd:	89 d0                	mov    %edx,%eax
  4005df:	c1 e0 02             	shl    $0x2,%eax
  4005e2:	01 d0                	add    %edx,%eax
  4005e4:	c1 e0 02             	shl    $0x2,%eax
  4005e7:	89 ca                	mov    %ecx,%edx
  4005e9:	29 c2                	sub    %eax,%edx
  4005eb:	89 d0                	mov    %edx,%eax
  4005ed:	89 45 f8             	mov    %eax,-0x8(%rbp)
  4005f0:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  4005f4:	81 7d fc 0f 27 00 00 	cmpl   $0x270f,-0x4(%rbp)
  4005fb:	7e b9                	jle    4005b6 <main+0xaa>
*/
