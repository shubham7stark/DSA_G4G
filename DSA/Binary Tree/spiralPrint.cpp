#include<iostream>
#include<stack>

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


/*----------------------------------*/


void printSpiral(struct node* nod){

if(nod == NULL)return;

stack<struct node*> s1;
stack<struct node*> s2;

s1.push(nod);

while(!s1.empty() || !s2.empty()){

	while(!s1.empty()){
    
	struct node* temp1 = s1.top();
    s1.pop();
    cout << temp1->data << " ";
    if(temp1->right)
     s2.push(temp1->right);
   

    if(temp1->left)
	s2.push(temp1->left); 
   
   
   }	
   
	while(!s2.empty()){
    struct node* temp2 = s2.top();
    s2.pop();
    cout << temp2->data << " ";
    
	if(temp2->left)
     s1.push(temp2->left);
    if(temp2->right)
	s1.push(temp2->right); 
   }
	
	
}
	
}


 
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);
 
    return 0;
}



