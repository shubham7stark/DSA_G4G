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

bool search(node* root, int key){
	
	if(!root)
	return false;
	
	if(root->data == key)return true;
	
  return search(root->right,key) || search(root->left,key);

}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
   
    return 0;
}
