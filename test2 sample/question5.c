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
	struct treeNode *leftPtr;
	int data;
	struct treeNode *
	rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

int search(
	TREENODEPTR
	tree_ptr, int n)
{