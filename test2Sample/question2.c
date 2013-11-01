/* uriah sypolt
10/30/2013
CS 350
Computer Systems Concepts
Instructor: Dr. Bojan Cukic
SAMPLE TEST#2
Fall 2013
*/

/*
2.Assume the following data structure is declared in the program. Also, assume that integers require 4 bytes
of storage, floats require 8 bytes and each ASCII character is stored in 1 byte.

Please show what is printed out by each printf() statement in the program above and explain it shortly.
*/

#include <stdio.h>
union number{
	int x;
	float y;
	char s[10];
};
main (){
	union number val;
	val.x=5;
	printf("%d\n", val.x);
	//printf("%d\n", val.y);
	printf("%f\n", val.y);
	val.y=100.5;
	//printf("%d\n", val.y);
	printf("%f\n", val.y);
	printf("%s\n", val.s);
	scanf("%s",val.s);/* Assume user enters string ‘something’*/
	printf("%s\n", val.s);
	return 0;
}
/*
Please show what is printed out by each printf() statement in the program above and explain it shortly.
output
5               //vals "x" contain the value 5
0.00000000      //vals "y" value has not been assigned yet
100.5000000     //vals "y" contain the value 100.5
				//nothing was outputted because nothing is in vals "s" value
something       //'something' was typed in
something       //vals "s" value 'something' was outputted 
*/