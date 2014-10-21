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


void merge(node* root1, node* root2){
	
	struct node* current1 = root1;
	struct node* current2 = root2;
	
	struct snode* s1 = NULL;
    struct snode* s2 = NULL;
    
    if(root1 = NULL){
    	inorder(root2);
    }
    
	if(root2 = NULL){
    	inorder(root1);
    }
    
    while(!isEmpty(s1) || !isEmpty(s2) || current1 != NULL || current2!=NULL)
	{
    
		if (current1 != NULL || current2 != NULL )
        {
            // Reach the leftmost node of both BSTs and push ancestors of
            // leftmost nodes to stack s1 and s2 respectively
            if (current1 != NULL)
            {
                push(&s1, current1);
                current1 = current1->left;
            }
            if (current2 != NULL)
            {
                push(&s2, current2);
                current2 = current2->left;
            }
 
        }
      else{
      	
		   if(isEmpty(s1)){
        	   while (!isEmpty(s2))
                {
                    current1 = pop (&s2);
                    current1->left = NULL;
                    inorder(current1);
                }
                return ;
            }
         	
        	if(isEmpty(s2)){
        	   while (!isEmpty(s1))
                {
                    current2 = pop (&s1);
                    current2->left = NULL;
                    inorder(current1);
                }
                return ;
            }
            
       // Pop an element from both stacks and compare the
            // popped elements
            current1 = pop(&s1);
            current2 = pop(&s2);
 
            // If element of first tree is smaller, then print it
            // and push the right subtree. If the element is larger,
            // then we push it back to the corresponding stack.
            if (current1->data < current2->data)
            {
                printf("%d ", current1->data);
                current1 = current1->right;
                push(&s2, current2);
                current2 = NULL;
            }
            else
            {
                printf("%d ", current2->data);
                current2 = current2->right;
                push(&s1, current1);
                current1 = NULL;
            }
			 	
      }      
      
    }
    
}





/* Driver program to test above functions */
int main()
{
    struct node  *root1 = NULL, *root2 = NULL;
 
    /* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);
 
    /* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);
 
    // Print sorted nodes of both trees
    merge(root1, root2);
 
    return 0;
}


