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


int height(node* root){
	if(!root)return 0;
	int lHeight = height(root->left);
	int rHeight = height(root->right);
    return(lHeight > rHeight)?(lHeight + 1):(rHeight + 1);
}

int getMax(int arr[], int height){
	int max = arr[0];
	
	for(int i =0; i <height;i++)
	if(arr[i]>max)max=arr[i];
	
	return max;
}

void getMaxWidthRec(node* root, int* count,int level){

if(root){
	count[level]++;
    getMaxWidthRec(root->right,count,level+1);
    getMaxWidthRec(root->left, count,level+1);
}
}

int getMaxWidth(struct node* root){
	int width;
	int h = height(root);
	int *count = (int *)calloc(sizeof(int), h);
	
	int level;
	getMaxWidthRec(root,count,level);
	return getMax(count , h);
}


int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);
  root->right->right->left  = newNode(6);
  root->right->right->right  = newNode(7);
  printf("Maximum width is %d \n", getMaxWidth(root));
  getchar();
  return 0;
}


  
