#include <stdio.h>
#define  M 200
#define N 200
/*uriah sypolt       2013       cs350
*/
/*read me !!!!
main is at the end 

this program reads a maze in from a txt file 
**must have**
	1 on the oustide boarder must only have 2 zeros no more no less
	2 maze must use 0 for open space and 1 for wall
	3 you must know how big the maze is 

*/
/*read in start location (a,b) and size (x,y)
determins what side of the map the start location is on
and returns the direction it needs to be facing
returns a char (n||s||e||w)
*/
char enter (int a,int b,int x,int y){
	if (a==0){return 's';}
	else if (a==x-1){return 'n';}
	else if (b==0){return 'e';}
	else if (b==y-1){return 'w';}
}
/*reads in curent location (x,y) and the direction (dir)
move one step in the direction the man is facing 
returns nothing **over wrights x or y**
*/
void step (int *x,int *y,char dir){
	if (dir == 'e'){*y=*y+1;}
	else if (dir == 's'){*x=*x+1;}
	else if (dir == 'w'){*y=*y-1;}
	else if (dir == 'n'){*x=*x-1;}
}
/*reads in current direction and changes it from E>N>W>S>E
returns a char (n,e,s,w)
*/
char turnLeft (char dir){
	if (dir == 'e'){return 'n';}
	else if (dir == 's'){return 'e';}
	else if (dir == 'w'){return 's';}
	else if (dir == 'n'){return 'w';}
}
/*reads in current direction and changes it from E>S>W>N>E
returns a char (n,e,s,w)
*/
char turnRight (char dir){
	if (dir == 'e'){return 's';}
	else if (dir == 's'){return 'w';}
	else if (dir == 'w'){return 'n';}
	else if (dir == 'n'){return 'e';}
}
/*reads in the map(array), your location on the map (x,y), and the direction you are heading (dir)
it will look one step in front of you depending on your direction and see if it is a open spot (0)
 returns 1 if it safe to step there 0 if not  
*/
int openStright(char array[200][200],int x,int y,char dir){

	if (dir == 'e'){
		if (array[x][y+1]=='0'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 's'){
		if (array[x+1][y]=='0'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 'w'){
		if (array[x][y-1]=='0'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 'n'){
		if (array[x-1][y]=='0'){
			return 1;
		}else{
			return 0;
		}
	}	
}
/*reads in the map(array), your location on the map (x,y), and the direction you are heading (dir)
it will look one step in front of you depending on your direction and see if it is a wall (1)
 returns 1 if it is 0 if not  
*/
int wallStright(char array[200][200],int x,int y,char dir){
	if (dir == 'e'){
		if (array[x][y+1]=='1'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 's'){
		if (array[x+1][y]=='1'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 'w'){
		if (array[x][y-1]=='1'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 'n'){
		if (array[x-1][y]=='1'){
			return 1;
		}else{
			return 0;
		}
	}	
}
/*reads in the map(array), your location on the map (x,y), and the direction you are heading (dir)
it will look one step in front of you depending on your direction and see if a bread crum (x)
 returns 1 if safe 0 if not
*/
int breadCrumStright(char array[200][200],int x,int y,char dir){
	if (dir == 'e'){
		if (array[x][y+1]=='x'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 's'){
		if (array[x+1][y]=='x'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 'w'){
		if (array[x][y-1]=='x'){
			return 1;
		}else{
			return 0;
		}
	}else if (dir == 'n'){
		if (array[x-1][y]=='x'){
			return 1;
		}else{
			return 0;
		}
	}	
}
/*reads in the map(array), your location on the map (x,y), and the direction you are heading (dir)
this look to see if there is a wall to your right only 
returns 1 if there is a wall only 0 else
*/
int wallOnlyRight(char array[200][200],int x,int y,char dir){
	if (dir == 'e'){
		if (array[x+1][y]=='1'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 's'){
		if (array[x][y-1]=='1'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 'w'){
		if (array[x-1][y]=='1'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 'n'){
		if (array[x][y+1]=='1'){
			return 1;
		}
		else{
			return 0;
		}
	}
}
/*reads in the map(array), your location on the map (x,y), and the direction you are heading (dir)
this looks to see if there is a bread crum to your right
returns 1 if there is and 0 if not  
*/
int breadCrumOnlyRight(char array[200][200],int x,int y,char dir){
	if (dir == 'e'){
		if (array[x+1][y]=='x'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 's'){
		if (array[x][y-1]=='x'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 'w'){
		if (array[x-1][y]=='x'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 'n'){
		if (array[x][y+1]=='x'){
			return 1;
		}
		else{
			return 0;
		}
	}
}
/*reads in the map(array), your location on the map (x,y), and the direction you are heading (dir)
this looks to see if there is a open on your right
returns 1 if there is and 0 if not  
*/
int openRight(char array[200][200],int x,int y,char dir){
	if (dir == 'e'){
		if (array[x+1][y]=='0'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 's'){
		if (array[x][y-1]=='0'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 'w'){
		if (array[x-1][y]=='0'){
			return 1;
		}
		else{
			return 0;
		}
	}else if (dir == 'n'){
		if (array[x][y+1]=='0'){
			return 1;
		}
		else{
			return 0;
		}
	}
}
/*reads in the map (array), the start locations (a,b), and the end locations (c,d)
1 looks to see if it has made it to the start or the end
2 makes current location a x 
3 it looks for a bread crum or a wall on the right and if there is a opening stright
4 if not it will see it there is only a wall to the right if so it turns left
5 if there is not a wall it will turn right
no return
*/
void traverse (char array[200][200],int a,int b,int c,int d, char dir){
	//declorations
	int myX=a;														// seting the man to the start
	int myY=b;
	
	//end declorations
	
	while (1){
		printf("x,%d, y,%d dir %c \n",myX, myY, dir);                           // test location
		//fgetc(stdin);
		//printMaze(array,100,100);
		if ( myX==c && myY==d){
			array [myX][myY]='x';
			printf("you got out");
			break;
		}
		if ( myX==a && myY==b && array [myX][myY]=='x'){
			printf("no way out");
			break;
		}
		array [myX][myY]='x';
		if (array[myX-1][myY]=='x'&& array[myX+1][myY]=='x'&& array[myX][myY-1]=='x' && array[myX][myY+1]=='x'){
			dir = turnRight (dir);
			step(&myX,&myY,dir);
			//array [myX][myY]=dir;										//test location
		}else if (openStright(array,myX,myY,dir) && openRight(array,myX,myY,dir)){
			dir = turnRight (dir);
			//array [myX][myY]='R';	
		}else if (openStright(array,myX,myY,dir) && wallOnlyRight(array,myX,myY,dir)){
			step(&myX,&myY,dir);
			//array [myX][myY]=dir;										//test location
		}else if (openStright(array,myX,myY,dir) && breadCrumOnlyRight(array,myX,myY,dir)){
			step(&myX,&myY,dir);
			//array [myX][myY]=dir;										//test location
		}else if (wallStright(array,myX,myY,dir) && openRight(array,myX,myY,dir)){
			dir = turnRight (dir);
			//array [myX][myY]='R';										//test location
		}else if (wallStright(array,myX,myY,dir) && wallOnlyRight(array,myX,myY,dir)){
			dir = turnLeft (dir);
			//array [myX][myY]='L';										//test location
		}else if (wallStright(array,myX,myY,dir) && breadCrumOnlyRight(array,myX,myY,dir)){
			dir = turnRight (dir);
			step(&myX,&myY,dir);
			//array [myX][myY]=dir;										//test location		
		}else if (breadCrumStright(array,myX,myY,dir) && openRight(array,myX,myY,dir)){
			dir = turnRight (dir);
			//array [myX][myY]='R';										//test location
		}else if (breadCrumStright(array,myX,myY,dir) && wallOnlyRight(array,myX,myY,dir)){
			step(&myX,&myY,dir);
			//array [myX][myY]=dir;										//test location		
		}else if (breadCrumStright(array,myX,myY,dir) && breadCrumOnlyRight(array,myX,myY,dir)){
			dir = turnRight (dir);
			step(&myX,&myY,dir);
			//array [myX][myY]=dir;										//test location		
		}
	}
}
/* reads in the map (array), the start (a,b), the end (c,d), and the acual sixe (x,y)
this will start from the top right corner of the map and work its way counter clockwise
to find the the start and end locations 
no return *but* reassigns start (a,b) and end (c,d)
*/
void startEnd(char array[200][200],int *a,int *b,int *c,int *d, int x, int y ){
	//declorations
	int foundStart=0;
	int i; 
	//end declorations
	
	for (i=0;i<x;i++){
		if (array[i][0]=='0'){
			if (foundStart==0){
				*a=i;
				*b=0;
				foundStart++;
			}
			else{
				*c=i;
				*d=0;
			}
		}
	}
	for (i=0;i<y;i++){
		if (array[x-1][i]=='0'){
			if (foundStart==0){
				*a=x-1;
				*b=i;
				foundStart++;
			}
			else{
				*c=x-1;
				*d=i;
			}
		}
	}
	for (i=x-1;i>=0;i--){
		if (array[i][y-1]=='0'){
			if (foundStart==0){
				*a=i;
				*b=y-1;
				foundStart++;
			}
			else{
				*c=i;
				*d=y-1;
			}
		}
	}
	for (i=y-1;i>=0;i--){
		if (array[0][i]=='0'){
			if (foundStart==0){
				*a=0;
				*b=i;
				foundStart++;
			}
			else{
				*c=0;
				*d=i;
			}
		}
	}
	return;
}
/* reads in the map (array) and the acual sixe (x,y)
this uses a nested for loop to print out want is in each location in the 2 d map
no return *but* wrights to screen
*/
printMaze(char array[200][200],int x,int y){
	//declorations
	int i,j=0;														// navigateing the array
	//end 
	
	for (i=0; i<x; i++){											// prints the maze to the screen
		for (j=0; j<y; j++)  {
			printf("%c",array[i][j]);
		}
	printf("\n");
	}																// end print out
	return;
}
main(){
	//decloration
	char array[M][N]={0};
	FILE *fptr;
	char c1;														//your char
	char file_name[20];												//name of file
	char dir;														//direction
	int i,j;														//itorator
	int x,y;							 							//map size
	int a,b=0;														//start location
	int c,d=0;														//end location
	// decloration end
	//getting data
	printf("how many rows in your map\n");							// ask for the hight of the map
	scanf("%d",&x);
	printf("how many columes in your map\n");						// ask for the width of the map 
	scanf("%d",&y);
	printf("Type in the name of the file containing the Field\n");	// ask for the file with the maze
	scanf("%s",file_name);
	//end getting data
	
	fptr=fopen(file_name,"r");										// save the maze to fptr
	
	for (i=0; i<x; i++){											// inputs the maze in to an array
		for (j=0; j<y; j++){
			c1=fgetc(fptr); 
			while ( !((c1 == '1')||(c1 =='0')) )c1=fgetc(fptr);
			array[i][j]=c1;
		}				
	}																//end maze set up
	fclose(fptr);
	printMaze(array,x,y);
	startEnd(array,&a,&b,&c,&d,x,y);
	dir=enter(a,b,x,y);
	traverse (array,a,b,c,d,dir);
	printMaze(array,x,y);
}