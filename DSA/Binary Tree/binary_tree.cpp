#include<stdio.h>
#include<stdlib.h>

struct node{	
int data;
struct node *left;
struct node* right;
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

bool identical(node* a, node*b){
	if(a == NULL && b == NULL)return 1;
	if(a != NULL && b != NULL){
		return(identical(a->right, b->right) &&
		        identical(a->left, b->left) &&
		        (a->data == b->data)
				);
	}
    return 0;			
}

int main(){
struct node *root1 = newnode(1);
    struct node *root2 = newnode(1);
    root1->left = newnode(2);
    root1->right = newnode(3);
    root1->left->left  = newnode(4);
    root1->left->right = newnode(5); 
 
    root2->left = newnode(2);
    root2->right = newnode(3);
    root2->left->left = newnode(4);
    root2->left->right = newnode(5); 
 
    if(identical(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");

	printpostorder(root1);
	printf("%s", "\n");
	return 0;
	
}

