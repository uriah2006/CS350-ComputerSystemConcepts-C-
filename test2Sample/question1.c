/* uriah sypolt
10/30/2013
CS 350
Computer Systems Concepts
Instructor: Dr. Bojan Cukic
SAMPLE TEST#2
Fall 2013
*/

/*1. Portability of programs is one the important software engineering goals. Different systems have different
conventions regarding the implementation of basic data types. Modify function void displayBits(unsigned), so 
that it is portable between systems using 2 - byte, 4 - byte, 8 - byte, 16 - byte, 32 - byte and larger unsigned
integers (the function below is tailored for 2 - byte - 16 bit unsigned integers).

HINT: Correct solution requires minimal code changes. You may not ask user to type in the size of an unsigned
integer.
*/
void dispalyBits(unsigned value){
	unsigned c, displayMask;
	displayMask= 1 << 15
	
	printf("%u = ",value);
	
	for (c = 1;c <= 16;c++){
		putchar(value & displayMask ? '1' : '0')
		value <<= 1;
		if (c % 8 == 0){
			putchar(' ');
		}	
	}
	putchar('\n');
}