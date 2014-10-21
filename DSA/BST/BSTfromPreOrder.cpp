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

struct node* insert(node* root, int key){
	
	if(!root){
	return newNode(key);
	}
	if(root->data > key){
		root->left = insert(root->left,key);
	}

	if(root->data < key){
		root->right = insert(root->right,key);
	}
  return root;

}

//.................... START OF STACK RELATED STUFF....................
// A stack node
 struct snode{
 	struct node* node;
 	struct snode* snode;
 }; 
 
 void push(struct snode** s, node* node){
 	
 	struct snode* temp = (struct snode*)malloc(sizeof(struct snode));
	
	temp->node = node;
	temp->snode = *s;
	*s = temp; 
 }
 
 struct node* pop(struct snode** s){
 	struct node* nod = (*s)->node;
 	struct snode *st;
    st=*s;
 	(*s) = (*s)->snode;
 	free(st);
 	return nod;
 }
// Fucntion to check whether the stack is empty or not
int isEmpty(struct snode *s)
{
    if (s == NULL )
        return 1;
 
    return 0;
}
//.................... END OF STACK RELATED STUFF....................


/*
/*---------------------------recursion based solution

struct node* constructTree(int a[], int start, int end){

if(start>end)return NULL;

 struct node* root = newNode(a[start]);
int i;
for(i = start+1; i <= end;)
{
   if(a[i] > a[start])break;
   else  i++;
}
 
root->right = constructTree(a,i,end);
root->left = constructTree(a,start+1,i-1);

return root;
}

*/

void printInorder (node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 


int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    node *root = constructTree(pre,0,size-1);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}
