#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node));
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

struct node* constructTreeUtil(int arr[], int* preIndex, int key, int min, int max, int size){

if(*preIndex >= size)return NULL;

struct node* root = NULL;


if(key >min && key < max)
{
	root = newNode(key);
    *preIndex = *preIndex + 1;


	if(*preIndex < size)
	{
	root->left = constructTreeUtil( arr, preIndex, arr[*preIndex],
                                        min, key, size );
     root->right = constructTreeUtil( arr, preIndex, arr[*preIndex],
                                         key, max, size );
   }
}

//printf(*preIndex);

return root;	
}



struct node* constructTree(int* arr, int size){

int preIndex = 0;

return constructTreeUtil(arr,&preIndex,arr[0], INT_MIN,INT_MAX,size);

}


void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d", node->data);
    printInorder(node->right);
}


int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    struct node *root = constructTree(pre, size);
 
    printf("   Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}
