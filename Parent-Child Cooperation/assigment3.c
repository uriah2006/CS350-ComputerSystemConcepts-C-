/*Uriah Sypolt
cs 350 10/18/2013

*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define  M 800

void toArray1D(int array[800],char file_name[30]);
void split();
int main(){
//decoration	
	pid_t child_L;
	pid_t child_R;
	char file_name[30];							//file name
	int array[M]={0};
	int i;



//get data
	printf("Type in the name of the file containing the text:");
	scanf("%s",file_name,);
	
//

	while ()

}

void toArray1D(array,file_name){
	FILE *fptr;
	fptr=fopen(file_name,"r");
	
	for (i=0; i<800;i++){
		num=fgeti(fptr);
		array[i]=num;
	}
}





/*
#include <unistd.h>     /* Symbolic Constants *
#include <stdio.h>      /* Input/Output *
#include <stdlib.h>     /* General Utilities *
#include<errno.h>

int main()
{   
    pid_t leftchild;
    pid_t rightchild;
    pid_t pid;
    int level=0;
    int max;


    printf("Enter in max level for process tree: ");
    scanf(" %d", &max);




    pid=getpid();
        fprintf(stderr,"I am the parent process with and id of: %ld\n", (long)getpid());
    for(; level<max; level++){

        leftchild=fork();
          if (leftchild == -1)
           {   

              fprintf(stderr, "can't fork, error %d\n", errno);
              exit(EXIT_FAILURE);
           }

        if(leftchild==0){
            fprintf(stderr,"Level is %d, i am %ld , my parent is %ld\n",level, (long)getpid(), (long)getppid());
            continue;
        }



        else{
            rightchild=fork();

            if(rightchild==0){
                fprintf(stderr,"Level is %d, i am %ld , my parent is %ld\n",level, (long)getpid(), (long)getppid());

                continue;
            }
        }
    wait(NULL);
    wait(NULL);
    break;

    }   

}

*/


/*
int main()
{  pid_t child_pid;
   int i;

   child_pid=fork();
   if (child_pid<0)  
    { printf("Failed to fork\n"); exit(-1); } 

   if (child_pid==0) /*child code*//*   
    for (i=0; i<5; i++)
           printf("i=%d, pid=%ld\n",i,(long)getpid());        
   else {/*parent code*//*
     wait(NULL);
    for (i=5; i<10; i++)
           printf("i=%d, pid=%ld\n",i,(long)getpid());        
   }

   /*child & parent*//*
   printf("Process %ld, parent %ld \n",(long)getpid(),(long)getppid());

   return 0;
}

Program output:
i=0, pid=21266
i=1, pid=21266
i=2, pid=21266
i=3, pid=21266
i=4, pid=21266
Process 21266, parent 21265 
i=5, pid=21265
i=6, pid=21265
i=7, pid=21265
i=8, pid=21265
i=9, pid=21265
Process 21265, parent 20976
*/