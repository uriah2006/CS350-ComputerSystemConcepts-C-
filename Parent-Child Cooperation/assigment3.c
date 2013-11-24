/*Uriah Sypolt
cs 350 10/18/2013

*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#define  M 800
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

void toArray1D(int array[M],char file_name[30]);
int * recursiveProcessTree(int array[M],int size);
int main(){
	//decoration	
	char file_name[30];							//file name
	int array[M]={0};
	int i=0;
	
	//get data
	printf("Type in the name of the file containing the text:");
	scanf("%s",file_name);
	
	//
	
	toArray1D(array,file_name);

	alarm(5);
	recursiveProcessTree(array,(sizeof(array)/4));
	
	i++;
	printf ("%d \n",i);
	/*for (i=0;i<sizeof(array)/4;i++){
		printf ("%d \n",array[i]);
	}
	*/
	
	
	return 0;
}

void toArray1D(int array[M],char file_name[30]){
	FILE *fptr = fopen(file_name,"r");
	int num;
	int i = 0;
	
	fscanf (fptr, "%d", &num);    
	while (!feof (fptr)){  
		array[i]=num;
		i++;
		fscanf (fptr, "%d", &num);      
    }
	fclose (fptr);        
}

int * recursiveProcessTree(int array[M],int size){
	//decoration
	int i=0, j=0, k=0;												//i j and k are used for sorting
	int left[size/2], right[size/2]; 
	memcpy(left, array, size/2); 
	memcpy(right, &array[size/2], size); 
	pid_t child;
	
	
	// if you need to recurs
    if (size>100){
	
		//fork it!!
		child=fork();
		if (child < 0){
			printf("failed to fork");
			exit(-1);
		}
		
		
		
		//child go left
		if (child==0){
			recursiveProcessTree(left,sizeof(left)/4);
		}
		//parent go right
		else{
			wait(NULL);
			recursiveProcessTree(right,sizeof(right)/4);
		}
		
		/*trying to join every thing back up **************************************
		while (child = waitpid(-1, NULL, 0)) {
			if (errno == ECHILD) {
				break;
			}
		}
		*/
	}
    // time to sort and return
	// TODO
	//sort(array);
    while(k<size){
		if(left[i] < right[j]){
			array[k] = left[i];
			i++;
		}
		else{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	return array;
}

/*
pid_t child_pid;
   int i;

   child_pid=fork();
   if (child_pid<0)  
    { printf("Failed to fork\n"); exit(-1); } 

   if (child_pid==0) //child code  
    for (i=0; i<5; i++)
           printf("i=%d, pid=%ld\n",i,(long)getpid());        
   else {//parent code
     wait(NULL);
    for (i=5; i<10; i++)
           printf("i=%d, pid=%ld\n",i,(long)getpid());        
   }

   //child & parent
   printf("Process %ld, parent %ld \n",(long)getpid(),(long)getppid());

   return 0;
}
*/