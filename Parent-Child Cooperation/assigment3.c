/*Uriah Sypolt
cs 350 10/18/2013

*/
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#define  M 800
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

void toArray1D(int array[M],char file_name[30]);
void recursiveProcessTree(int array[M],int start, int end);
int comp(const int * a,const int * b);
int main(){
	//decoration	
	char file_name[30]="test2.txt";							//file name
	int array[M]={0};
	int i=0;
	
	//get data
	//printf("Type in the name of the file containing the text:");
	//scanf("%s",file_name);
	
	//fills a one dimensional array with the contents from a file
	toArray1D(array,file_name);
	
	//error catch
	//alarm(5);
	
	recursiveProcessTree(array,0,(sizeof(array)/4));
	
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

void recursiveProcessTree(int array[M],int start, int end){
	//decoration
	int i=0, j=0, k=0;												//i j and k are used for sorting
	pid_t child;
	
	
	// if you need to recurs
    if ((end-start)>100){
	
		//fork it!!
		printf("child not born yet\n");
		child=fork();
		if (child == -1){
			perror("failed to fork");
		}
		
		//child go left
		else if (child < 0){
			recursiveProcessTree(array,start,(end/2)-1 );
			printf("child done\n");
		}
		
		//parent go right
		else{
			recursiveProcessTree(array, end/2 ,end);
		}
		/*trying to join every thing back up **************************************
		*/
	}
    // time to sort and return
	// TODO
	//sort(array);
    qsort(array,(end-start),sizeof(array[start]),comp) ;
}

//got it from http://cplus.about.com/od/learningc/ss/pointers2_8.htm
int comp(const int * a,const int * b)
{
  if (*a==*b)
    return 0;
  else
    if (*a < *b)
        return -1;
     else
      return 1;
}
/*
int main()
{
    pid_t b; // note that the actual return type of fork is 
             // pid_t, though it's probably just an int typedef'd or macro'd

    b = fork();
    if (b == -1) perror("Fork failed");
    else if (b > 0) {
        printf("My name is Manish\n"); // parent process
    else
        printf("My name is Anil\n"); // child process

    printf("The value of b is %d\n", b);
    return 0;
}
*/