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
union number
{
	int x;
	float y;
	char s[10];
};
main() {
union number val;
val.x = 5;
printf("%d\n", val.x);
printf("%d\n", val.y);
val.y = 100.5;
printf("%d\n", val.y);
printf("%s\n", val.s);
scanf(“%s”, val.s); /* Assume user enters string ‘sometest’*/
printf("%s\n", val.s);
return 0;
}