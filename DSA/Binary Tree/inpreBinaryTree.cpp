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

void printInOrder(node* nod){
	if(nod == NULL)return;
	printInOrder(nod->right);
	printf("%d", nod->data);
	printInOrder(nod->left);
}


int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

struct node* buildTree(char in[], char pre[], int inStart, int inEnd){
	static int preIndex = 0;
 
    if(inStart > inEnd)return NULL;
  
	struct node* tNode = newNode(pre[preIndex++]);

   if(inStart == inEnd)return tNode;
   
   int inIndex = search(in, inStart,inEnd, tNode->data);
   tNode->right = buildTree(in, pre, inStart,inIndex-1);
   tNode->left = buildTree(in,pre,inIndex+1,inEnd);
}

// 9414322859

/* Driver program to test above functions */
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);
 
  /* Let us test the built tree by printing Insorder traversal */
  printf("\n Inorder traversal of the constructed tree is \n");
  printInOrder(root);
  getchar();
}
