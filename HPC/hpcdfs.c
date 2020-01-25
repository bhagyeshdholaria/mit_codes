#include <stdio.h> 
#include <stdlib.h> 
#include<omp.h>

struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

struct node* newNode(int data) 
{ 
	struct node* node = (struct node*); 
	malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

void create_r(treenode * temp) //workhorse for creation
{
Accept choice whether data is added to left of temp->data;
if ch=‘y’
{
Allocate a memory for curr and accept data;
temp->left=curr;
create_r(curr);
}
Accept choice whether data is added to right of temp->data;
if ch=‘y’
{
Allocate a memory for curr and accept data;
temp->right=curr;
create_r(curr);
}

void printInorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first recur on left child */
	printInorder(node->left); 

	/* then print the data of node */
	printf("%d ", node->data); 

	/* now recur on right child */
	printInorder(node->right); 
} 

Algorithm create_r() //Driver for creation
{
Allocate memory for root and accept data;
create_r(root);
}

int main()
{
tree bt;
bt.create_r();
}
tree::tree() //constructor
{
root=NULL;
}

int main() 
{ 
	struct node *root = newNode(1); 
	root->left= newNode(2); 
	root->right= newNode(3); 
	root->left->left=newNode(4); 
	root->left->right =newNode(5); 
	printf("\nInorder traversal of binary tree is \n"); 
	printInorder(root); 
	return 0; 
} 

