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

/*
int* dia(struct node* nod){
	int a[2];
	a[0] = 0;
	a[1] = 0;
	
	if(nod == NULL) {
    return a;
	}
	
	if(nod->right == NULL && nod->left == NULL)
	{
		a[0] = 1;
		a[1] = 1;
	   return a;
	}
	
	int b[2] = dia(nod->right);
	int c[2] = dia(nod->left);
		
	a[1] = b[0] + c[0] + 1;	
	
	if(a[1]<b[1]) a[1] = b[1];
	if(a[1]<c[1]) a[1] = c[1];

    a[0] = 1+ (b[0]>c[0])?b[0]:c[0];
    return a;
}
*/


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
 
 //int k[2] = dia(root);
 // printf("Diameter of the given binary tree is %d\n", k[1]);
 
  getchar();
  return 0;
}



