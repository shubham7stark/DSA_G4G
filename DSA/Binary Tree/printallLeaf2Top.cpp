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

void printArray(int arr[], int length){
  for(int i = 0; i <length; i++){
  	printf("%d", arr[i]);
  }
  printf("%s", "/n");
}

void printleafpath(node* nod, int arr[], int length){
	if(!nod)return; 
	
	arr[length] = nod->data;
	length++;	
	if(nod->right == NULL && nod->left == NULL)
	 printArray(arr, length);
	 else{
	 	printleafpath(nod->left, arr, length);
	 	printleafpath(nod->right, arr, length);
	 }
}



int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
 int arr[20] ;
  /* Print all root-to-leaf paths of the input tree */
  printleafpath(root,arr, 0);
 
  getchar();
  return 0;
}
