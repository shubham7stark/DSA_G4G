#include<iostream>
using namespace std;

template <class T>
class doublynode{
	//friend doublylist<T>; 
	private:
		T data;
		doublynode<T>* left;
		doublynode<T>* right;
}; 



template <class T>
class doublylist{
   private:
    doublynode<T>* head;
	int height;

 public:		
   doublylist(){
   	head = 0;
   }
   ~doublylist();
    doublylist<T>& Insert(int k,T&x);
 	doublylist<T>& Delete(int k,T&x);
    
    int search(const T &x);
    
    bool find(int k,T&x);
    bool isEmpty(){
    	return head==0;
    }
    int length()const;
};

/*---------------------------------------*/
template<class T>
doublylist<T>& doublylist<T>::Insert(int k,T&x){
	if(k<0) return ; //throw  OutOfBounds();
	
	doublylist<T>*p, *q, *r , *temp;
	p = head;
	if(p == NULL){
	p->data = x;
	p->left = NULL;
	p->right = NULL;
   }
   else{
   
   temp = p;
   for(int i =1;i<k && temp;i++)
   temp= temp->right;
   
   if(!temp)return NULL;
   
   q = temp->right;
   
   if(q)
   {r->right = q;
   q->left = r;
   }
   temp->right = r;
   r->left = temp;
   
   }
   return *this;
   
}

/*--------------------------------------*/

doublylist<T>& doublylist<T>::delete(int k, T&x){

if(k<1)return 0;
doublynode<T> *p, *q, *r, *temp;
p = head;


for(int i = 0; i < k && temp;i++)
temp = temp->right;

q = temp->right;
r = q-> right;

if(q){
temp->right = r;
if(r)
r->left = temp;	
}

delete q;
return *this;

}

/*--------------------------------*/



















