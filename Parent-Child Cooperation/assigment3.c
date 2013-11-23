/*Uriah Sypolt
cs 350 10/18/2013

*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define  M 800

void toArray1D(int array[800],char file_name[30]);
int * recursiveProcessTree(int array[M]);
int main(){
	//decoration	
	char file_name[30];							//file name
	int array[M]={0};
	int i;
	
	//get data
	printf("Type in the name of the file containing the text:");
	scanf("%s",file_name,);
	
	//
	toArray1D(array,file_name);

	//
	
	
	int * recursiveProcessTree(int array[M]){

	
	
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

int * recursiveProcessTree(int array[M]){

	//decoration
	pid_t forkRight;
	pid_t forkLeft;
	
  	
	// if you need to recurs
    if (sizeof(array)>100){
		
		forkRight=fork();
		
		if (forkRight==0){
			printf("failed to right fork")
			exit(-1);
		}
		
		recursiveProcessTree(int array[M]);
		
		wait(NULL);
		
		
		forkLeft=fork();
		if (forkLeft==0){
			printf("failed to left fork")
			exit(-1);
		}
		
		recursiveProcessTree(int array[M]);
		
		wait(NULL);
	}
    // time to sort and return
    else{
	// TODO
	//sort(array)
	}
        

}