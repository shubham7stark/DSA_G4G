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


void doubleTree(struct node* nod){
	
	if(nod == NULL)return;
	
	struct node* temp = newNode(nod->data);
    doubleTree(nod->right);
    doubleTree(nod->left);
    temp->left = nod->left;
    nod->left = temp;
   
}


void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left); 
  printf("%d ", node->data);
  printInorder(node->right);
}


int main()
{
  
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  
  printf("Inorder traversal of the original tree is \n");
  printInorder(root);
 
  doubleTree(root);
   
  printf("\n Inorder traversal of the double tree is \n");  
  printInorder(root);
    
  getchar();
  return 0;
}
