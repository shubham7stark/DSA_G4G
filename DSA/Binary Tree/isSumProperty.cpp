#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

bool isSum(struct node* nod){
	if(nod == NULL)return 1;
	if(nod->right == NULL && nod->left == NULL)
	return 1;
	else{
		
	int left_data = 0, right_data = 0;
	if(nod->right)
	  right_data = nod->right->data;
	if(nod->left)
	   left_data = nod->left->data;
	   
	if(nod->data == left_data + right_data)
		if(isSum(nod->right) && isSum(nod->left))
		return 1;
    }
    
	return 0;
	
}



int main()
{
  struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(isSum(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
 
  getchar();
  return 0;
}
