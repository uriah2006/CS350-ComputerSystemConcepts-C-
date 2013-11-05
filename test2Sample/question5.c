/* uriah sypolt
10/30/2013
CS 350
Computer Systems Concepts
Instructor: Dr. Bojan Cukic
SAMPLE TEST#2
Fall 2013
*/
/*
5. Assume you have built the binary search tree composed of the following elements:

(tree diagram)

Write a C function int search(TREENODEPTR tree_ptr, int n) which should determine
whether n exists in the binary tree. If n exists, the function should print out the
numbers encountered in the nodes during the search and return the number of visited
nodes. For example, the function call search(root, 9) should cause the printout 24,
12, 8, 9, and the returned value should be 4 (24 and 12 and 8 and 9 have been 
visited in this search). In case of search(root, 28),the function should print out 
the visited nodes (24, 44, 29) and return - 3, meaning the node with number 28 is 
not found ( - ) and 3 comparisons have been performed.

(HINT: Iterative and recursive solutions exist. As long as the program is correct, 
you will receive full points, regardless of the solution you choose).
*/

struct treeNode {
	int data;
	struct treeNode *leftPtr;
	struct treeNode *rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;
 

int recursive(TREENODEPTR tree_ptr, int find);	
int iterative(TREENODEPTR tree_ptr, int find);

int main (){
	TREENODEPTR rootPtr;

	insertNode(&rootPtr, 24);
	insertNode(&rootPtr, 12);
	insertNode(&rootPtr, 44);
	insertNode(&rootPtr, 8);
	insertNode(&rootPtr, 16);
	insertNode(&rootPtr, 29);
	insertNode(&rootPtr, 80);
	insertNode(&rootPtr, 3);
	insertNode(&rootPtr, 9);
	insertNode(&rootPtr, 18);
	insertNode(&rootPtr, 56);
	insertNode(&rootPtr, 89);
	
	//decorations 
	int find;	
	
	
	//grab values
	printf("what value do want to trace:");
	scanf("%d",&find);
	
	//recursive
	
	int recursive(&rootPtr, find);
	
	//iterative
	int iterative(&rootPtr, find);
	return 0;	
}
int recursive(TREENODEPTR tree_ptr, int find){
	return 0;
}
int iterative(TREENODEPTR tree_ptr, int find){
	int n = tree_ptr->data;
	while (n!=find){
		n = tree_ptr -> data;
		printf("%d",n);
		if (find > n){
		tree_ptr = tree_ptr-> rightPtr;
		}
		else {
		tree_ptr = tree_ptr-> leftPtr;
		}
	}
	
	return n;
}