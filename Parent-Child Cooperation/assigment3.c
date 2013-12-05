/*Uriah Sypolt
cs 350 10/18/2013

*/
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>  // for line 97
#define  M 800

void toArray1D(int array[M],char file_name[30]);
void forkingTree(int array[M]);
int comp(const void * a,const void * b);
int main(){
	//decoration	
	char file_name[30];									//file name
	int array[M]={0};
	int i=0;
	
	//get data
	printf("Type in the name of the file containing the text:");
	scanf("%s",file_name);
	
	//fills a one dimensional array with the contents from a file
	toArray1D(array,file_name);
	
	
	//splits up the array and sorts it
	forkingTree(array);
	
	
	// pints out the sorted array
	for (i=0;i<sizeof(array)/4;i++){
		printf ("%d \n",array[i]);
	}
	
	
	return 0;
}

void toArray1D(int array[M],char file_name[30]){
	//opens file
	
	FILE *fptr = fopen(file_name,"r");
	
	//value from file
	int num;
	
	//start of the array
	int i = 0;
	
	fscanf (fptr, "%d", &num);    
	while (!feof (fptr)){  
		array[i]=num;
		i++;
		fscanf (fptr, "%d", &num);      
    }
	fclose (fptr);        
}

void forkingTree(int array[M]){
	//decoration
	
	//i j and k are used for sorting
	int i=0, j=0, k=0;

	//this controls how many time I am going to go through the for loop
	int current, bottem=3;
	
	// whose your daddy ... 
	pid_t kid, dad=getpid();

    //for every loop it will make a fork to make a symmetrical tree
	for(current=0; current<bottem; current++){
		
		// FORK THE KID!!
		kid=fork();
		
		//makes sure the fork .... forked
		if (kid == -1){
			printf("failed fork");
			exit(1);
		
		// this is the parent it is essentially the left leg
		}else if (kid > 0) {
			printf ("going right\n");
			continue;
		
		// this is the kid it is essentially the right leg
        }else{
			printf ("going left\n");
			continue;
		}
	}
	
	// I am your daddy!!
	if (dad != getpid()){
		kill (getpid(), SIGUSR1);
	}
	
	// daddy goes on nap time so it looks like I am sorting 
	sleep(4);
	
	// remember that I made you laugh so I should get some credit
	qsort(array,800,sizeof(array[0]),comp);
}


//got it from http://cplus.about.com/od/learningc/ss/pointers2_8.htm 
//I knew where is was so I was not about to write it up again
int comp(const void * a,const void * b)
{
  int A = *((int*)a);
  int B = *((int*)b);
  if (A==B)
    return 0;
  else
    if (A < B)
        return -1;
     else
      return 1;
}