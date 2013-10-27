/* Uriah Sypolt 
cs 350 10/18/2013
this program will read in a txt file and fix any spacing issues so that the output will be left and right justified*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {  /* self-referential structure */
   char data[40];
   struct listNode *nextPtr;
   struct listNode *lastPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *,LISTNODEPTR *, char[40]);
void delete(LISTNODEPTR *);
int peek(LISTNODEPTR);
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
int main(){
//decoration
	FILE *fptr;									//pointer to the file
	LISTNODEPTR startPtr = NULL;				//pointer to the head
	LISTNODEPTR lastPtr = NULL;					//pointer to the last
	LISTNODEPTR endPtr = NULL;					//pointer to the tail
	LISTNODEPTR bufferPtr = NULL;				//pointer for printing back out
	int end=0;									//boolean for end of paragraph
	int realCount;								//count to back track by one
	int moreSpaces;								//how many spaces the print out needs
	int wS;										//just in case we need more white spaces then we have gaps 
	int wordsOnLine=0;							//how many words can fit on a line
	int count=0;								//letter counter
	int i,j,lineCount=0;						//counter
	int line;									//size of the line 
	char c; 									//the next char getting read in 
	char* word = malloc(40*sizeof(char));		//the word
	
	char file_name[30];							//file name
	
//end decoration
//get data
	printf("Type in the name of the file containing the text:");
	scanf("%s",file_name);
	printf("how long is your line:");
	scanf("%d",&line);
	for (i=0;i<50;i++){
		printf("\n");
	}
//end get data	
	fptr=fopen(file_name,"r");
	if (fptr == NULL) perror ("Error opening file");
	else{
		while (!feof(fptr)){												//loop for the whole file
			while (!feof(fptr)){											//loop for the paragraph 
				c=fgetc(fptr);
//test point	//printf("%s \n",word);
				//printf("char: %c \n",c);
				//printf("count: %d \n",count);
				//fgetc(stdin);
				if ((c==' '||c=='\r'||c=='\n')&&count==0){					//white space or end of line and not a word
					if (end && (c=='\r'||c=='\n')){							//check end of paragraph 
						end=0;
						break;
					}
					else if (c=='\r'||c=='\n'){							//check end of paragraph 
						//printf("that ");
						end++;
					}
				}else if ((c==' '||c=='\r'||c=='\n')&&count!=0){ 			//end of line or space with word				
//test point		//printf("what is in word %s \n",word);
					insert(&lastPtr,&startPtr, word);						//send word to linked list 
					if (endPtr==NULL){
						endPtr = startPtr;
					}
					for (i=0;i<=40;i++){								//wipe word
						word[i]='\0';
					}
//test point		//printf("left in word %s \n",word);
					if (end && (c=='\r'||c=='\n')){							//check end of paragraph 
						end=0;
						break;
					}
					else if (c=='\r'||c=='\n'){							//check end of paragraph 
						//printf("that ");
						end++;
					}
					
					count=0;
				}else if (c!=' '||c!='\r'||c!='\n'){							//letter building a word
//test point		//printf("%d \n",count);
					word[count]=c;
					count++;
					end=0;
				}
			}
//test point printList(endPtr);
			bufferPtr = endPtr;
			while(!(isEmpty(endPtr))){										//loop to clear the linked list
				realCount=lineCount;										//last count
				lineCount=lineCount+peek(bufferPtr)+1;						//checking next count
//test point	//printf("linecount %i realcount %i peek %i wordsOnLine %i \n",lineCount, realCount, peek(bufferPtr), wordsOnLine);
				if (lineCount>line){										//check if the new is to much for the line
					moreSpaces=line-realCount;								//solving for how many spaces you need to fill line
//test point		//printf("moreSpaces %i=line %i-realCount %i \n",moreSpaces,line,realCount);
					for (i=0;i<wordsOnLine;i++){							//loops prints word to line 
						if (i>0 && !(moreSpaces == 0)){						//adds filler spaces
							wS=(int)((moreSpaces)/(wordsOnLine-1))+1;
							while (wS){
								printf(" ");
								moreSpaces--;
								wS--;
							}
						}
						printf("%s",endPtr->data);							//outputs word to line
						delete(&endPtr);									//deletes from linked list 
						if(!(i==wordsOnLine-1)){							//checks if word is at the end of the line 
							printf(" ");
						}
					}
					printf("\n");											// line	is done places new line
					lineCount=0;
					wordsOnLine=0;
					realCount=0;
				}
				else if (bufferPtr->data==NULL){							//last line need to be left justified							
					for (i=0;i<wordsOnLine;i++){
						printf("%s ",endPtr->data);
						delete(&endPtr);
					}
					printf("\n");
					lineCount=0;
					wordsOnLine=0;
					realCount=0;
				}
				else {
					wordsOnLine++;
					if (bufferPtr!=NULL){									//looks to see if the buffer is going to out of bounds	
						bufferPtr=bufferPtr->nextPtr;
					}
				}
			}
			printf("\n");
		}
	}
return 0;
}


/* Insert a new value into the double linked list */
void insert(LISTNODEPTR *pPtr, LISTNODEPTR *cPtr, char value[40]){
	int i;
	LISTNODEPTR newPtr,previousPtr, currentPtr;					//new node pointers
	newPtr = malloc(sizeof(LISTNODE));							//allocating memory for new node
	if (newPtr != NULL) {										//is space available
		for (i=0;i<=(strlen (value));i++){						//building the word in node
			newPtr->data[i] = value[i];
		}
		previousPtr = *pPtr;
		currentPtr = *cPtr;
		
		if (previousPtr == NULL && currentPtr == NULL) {		//if there is no nodes
			newPtr->lastPtr = NULL;
			newPtr->nextPtr = NULL;
 		
			*cPtr = newPtr;
			*pPtr = NULL;
		}else if (previousPtr == NULL) {						//if you only have 1 node
			currentPtr->lastPtr=previousPtr;
			currentPtr->nextPtr=newPtr;
			newPtr->lastPtr = currentPtr;
			newPtr->nextPtr = NULL;
 		
			*cPtr = newPtr;
			*pPtr = currentPtr;
		}else {													//makes all of the connections that is needed for double linked list
			previousPtr->nextPtr=currentPtr;
			currentPtr->lastPtr=previousPtr;
			currentPtr->nextPtr=newPtr;
			newPtr->lastPtr = currentPtr;
			newPtr->nextPtr = NULL;
 		
			*cPtr = newPtr;
			*pPtr = currentPtr;
        }
		
	}else{
		printf("%s not inserted. No memory available.\n", value);// error checker 
	}
}
/* Delete a list element */
void delete(LISTNODEPTR *sPtr){
	LISTNODEPTR tempPtr,killPtr;								//killptr will go to next node and kill the lastptr
	tempPtr = *sPtr;											//tempptr will give us something to free 
	killPtr = tempPtr->nextPtr;
	if (killPtr==NULL){
		*sPtr=NULL;
		return;
	}
	killPtr->lastPtr=NULL;
	*sPtr = (*sPtr)->nextPtr;
    free(tempPtr);
}

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty(LISTNODEPTR sPtr){
	return sPtr == NULL;
}
//Returns how the length of the next word
int peek(LISTNODEPTR currentPtr){
	if (currentPtr != NULL) {
		return strlen (currentPtr->data);
	}else {
		return '\0';
	}
}
	

/* Print the list */
void printList(LISTNODEPTR currentPtr){
	int i;
	if (currentPtr == NULL){
	//printf("List is empty.\n\n");
	}else {
		printf("The list is:\n");
		while (currentPtr != NULL) {
			for (i=0;i<=(strlen (currentPtr->data));i++){
				printf("%c", currentPtr->data[i]);
			}
			printf("-->");
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}