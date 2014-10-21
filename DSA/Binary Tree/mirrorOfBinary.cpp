#include<stdio.h>
#include<stdlib.h>

struct node{	
int data;
struct node *left;
struct node* right;
};


struct node* newNode(int data){
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


void converttomirror(node* nod){
	if(nod == NULL)return;
	
	else{
	struct node* p;
    p = nod->right;
    converttomirror(nod->left);
    converttomirror(nod->right);
    p = nod->right;
    nod->right = nod->left;
	nod->left = p;
	}
     
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
   
  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  printinorder(root);
   
  /* Convert tree to its mirror */
  converttomirror(root); 
   
  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");  
  printinorder(root);
   
  getchar();
  return 0;  
}
