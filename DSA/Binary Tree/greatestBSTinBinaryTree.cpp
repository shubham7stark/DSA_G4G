#include<stdio.h>
#include<stdlib.h>

struct node{	
int data;
struct node *left;
struct node* right;
};


struct node* newnode(int data){
	struct node* nnode = (struct node*) malloc(sizeof(struct node*));
	nnode->data = data;
    nnode->left = NULL;
    nnode->right = NULL;
   return (nnode);
};

void printinorder(node* nod){
	if(nod == NULL)return;
	printinorder(nod->right);
	printf("%d", nod->data);
	printinorder(nod->left);
}


