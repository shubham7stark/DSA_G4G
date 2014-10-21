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

struct node* sortedArrayToBST(int* arr, int start, int end){
	
	if(start > end)return NULL;
	int mid = (start + end)/2;
	
	struct node* temp = newNode(arr[mid]);
    
    temp->right = sortedArrayToBST(arr,mid+1,end);
    temp->left = sortedArrayToBST(arr,start,mid-1);
    
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    struct node *root = sortedArrayToBST(arr, 0, n-1);
    printf("\n inOrder Traversal of constructed BST ");
    inorder(root);
 
    return 0;
}


