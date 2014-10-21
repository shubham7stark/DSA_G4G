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

int getLevelUtil(node* nod,int data,int level){

 if(!nod)return 0;
 if(nod->data == data)return level;
 
 int download = getLevelUtil(nod->left,data,level+1);
   if(download != 0)return download;
   
  download = getLevelUtil(nod->right,data,level+1);
   return download;

}


/* Driver function to test above functions */
int main()
{
    struct node *root = new struct node;
    int x;
 
    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
 
    for (x = 1; x <=5; x++)
        printf(" Level of %d is %d\n", x, getLevelUtil(root, x,1));
 
    getchar();
    return 0;
}
