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


int heightbalanc(struct node* nod){
	
	if(nod == NULL)
	return 0;
	
	if((nod->right == NULL && nod->left == NULL))
	return 1;
	
	int a = heightbalanc(nod->right);
	int b = heightbalanc(nod->left);
	
	if(a == -1 || b == -1)return -1;
	
	if(a-b >= -1 && a-b <= 1)
	     return 1+ ((a>b)?a:b);
	     
	return -1;     

}


int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if(heightbalanc(root) + 1)
      printf("Tree is balanced" + heightbalanc(root));
    else
      printf("Tree is not balanced");    
 
 
    getchar();
    return 0;
}
