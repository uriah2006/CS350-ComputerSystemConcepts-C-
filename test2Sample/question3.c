/* uriah sypolt
10/30/2013
CS 350
Computer Systems Concepts
Instructor: Dr. Bojan Cukic
SAMPLE TEST#2
Fall 2013
*/

/*
3. The following program opens two files and calls function modify_file2 (inFilePtr, outFilePtr).
You may assume that both files are text files, and that both files can be opened properly.
*/
#include <stdio.h>
void modify_file2(FILE*, FILE*);

int main(int argc, int *argv[]){
	FILE *inFilePtr, *outFilePtr;
	int c;
	if (argc != 3){
		printf("Usage: copy infile output\n");
	}
	else{
		if ((inFilePtr = fopen(argv[1], "r")) != NULL){
			if ((outFilePtr = fopen(argv[2], "w")) != NULL){
				modify_file2(inFilePtr, outFilePtr);
			}
			else{
				printf("File\"%s\" could not be opened\n",argv[2]);
			}
		}
		else{
			printf("File \"%s\" could not be opened\n",argv[1]);
		}
	}
	return 0;
}

void modify_file2(FILE *inPtr, FILE *outPtr)
{
	int c;
	if ((c=fgetc(inPtr))!=EOF){
		modify_file2 (inPtr, outPtr);
		fputc(c, outPtr);
	}
}
/*
The file pointed by inFilePtr contains only the following line of text:
This is a test sentence in infile. 
Upon the execution of the above program, determine the contents of the
file pointed by outFilePtr.
*/