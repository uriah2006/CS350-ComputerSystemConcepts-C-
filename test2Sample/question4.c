/* uriah sypolt
10/30/2013
CS 350
Computer Systems Concepts
Instructor: Dr. Bojan Cukic
SAMPLE TEST#2
Fall 2013
*/

/*
4.
Write a short C program which, when invoked by the name of its executable ‘multiply’ in the command line,
followed by two or more operands, calculate s the result of the corresponding mathematical operator and
display s it on the screen. Your program should work correctly for any number of operands.
Example:

%multiply 8 3 2
%48
*/
#include <stdio.h>
 int main (int argc, int *argv[]) {
	int i=0;
	int r=1;
	if (argc<2){
		printf("ERROR: no numbers entered");
	}
	else{
		for (i=1; i< argc; i++) {
			r = r * (atoi(argv[i]));
		}
	}
	printf("%d\n",r);	
	return 0;
}
