#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
	struct node* left;
	struct node* right;
	int data;
};

struct node* newNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
};

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

bool isBST(node*  nod , int min , int max){
   
   if(nod == NULL) return true;

  if(nod->data > max || nod->data < min) return false;
  
  return isBST(nod->right, nod->data+1, max) && isBST(nod->left,min,nod->data -1); 

}



int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
  if(isBST(root,INT_MIN,INT_MAX ))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}  
