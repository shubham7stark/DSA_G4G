#include<stdio.h>
#include<stdlib.h>

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

bool isFoldable(node*root1,node*root2){
	if(!root1 && !root2) return true;
	if((root1 && !root2)||(!root1 && root2)) return false;
	
	return (isFoldable(root1->right,root2->left) && isFoldable(root1->left,root2->right))?true:false;
}


int main(void)
{
  /* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->left->right->right = newNode(6);
  root->right->left = newNode(5);
  root->right->left-> = newNode(7);
  
 
  if(isFoldable(root->right,root->left) == true)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }
 
  getchar();
  return 0;
}
