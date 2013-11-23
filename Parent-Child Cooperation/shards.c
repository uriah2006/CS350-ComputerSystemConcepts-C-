//test
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define  M 800

void toArray1D(int array[M],char file_name[30]);

int main(){
	int i;
	char file_name[30];							//file name
	int array[M]={0};
	
	printf("Type in the name of the file containing the numbers:");
	scanf("%s",file_name);
	
	toArray1D(array,file_name);
	

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