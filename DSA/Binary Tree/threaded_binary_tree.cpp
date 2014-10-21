#include<stdio.h>
#include<stdlib.h>

struct node{	
int data;
struct node *left;
struct node* right;
bool rightThread;
};


struct node* newnode(int data){
	struct node* nnode = (struct node*) malloc(sizeof(struct node*));
	nnode->data = data;
    nnode->left = NULL;
    nnode->right = NULL;
   return (nnode);
};

void printinorder(node* nod){
	if(nod == NULL)return;
	printinorder(nod->right);
	printf("%d", nod->data);
	printinorder(nod->left);
}


void printpreorder(node* nod){
	if(nod == NULL)return;
	printf("%d", nod->data);
	printpreorder(nod->right);
	printpreorder(nod->left);
}


void printpostorder(node* nod){
	if(nod == NULL)return;
	printpostorder(nod->right);
	printpostorder(nod->left);
    printf("%d", nod->data);
}





struct node* leftmost(struct node *n)
{
    if (n == NULL)
       return NULL;
 
    while (n->left != NULL)
        n = n->left;
 
    return n;
}
 
// C code to do inorder traversal in a threadded binary tree
void inOrder(struct node *root)
{
    struct node *cur = leftmost(root);
    while (cur != NULL)
    {
        printf("%d ", cur->data);
 
        // If this node is a thread node, then go to
        // inorder successor
        if (cur->rightThread)
            cur = cur->right;
        else // Else go to the leftmost child in right subtree
            cur = leftmost(cur->right);
    }
}

int maxHOfTree(node* nod){
 if(nod == NULL)return 0;
 else{
 	int a = maxHOfTree(nod->right);
    int b = maxHOfTree(nod->left);
    printf("%d",(a>b)?a:b);
    return ((a>b)?a:b) + 1;
 }
}




int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->right->left = newnode(4);
	root->right->right = newnode(5);	
	printpostorder(root);
	printf("%s", "\n");

    inOrder(root);

    printf("%d", maxHOfTree(root));
	return 0;
	
}

