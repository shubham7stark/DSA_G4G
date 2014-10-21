#include<iostream>

using namespace std;

template <class T>
class linkednode{
	//friend linkedlist<T>;
private:
	linkednode<T>* link;
	T data; 
};

template <class T>
class linkedlist{
   private:
    linkednode<T>* head;
	int height;

 public:		
   linkedlist(){
   	head = 0;
   }
   ~linkedlist();
 	linkedlist<T>& Delete(int k,T&x);
    linkedlist<T>& insert(int k,const T&x);
    
    int search(const T &x);
    
    bool find(int k,T&x);

    bool isEmpty(){
    	return head==0;
    }
    int length()const;
};

/*--------------------------------------*/
template<class T>
linkedlist<T>& linkedlist<T>::insert(int k, const T&x){
	if(k<0) return ; //throw  OutOfBounds();
	
	linkednode<T>*current = head;
    
    for(int i = 1; i < k && current; i++)
    current = current->link;
    
    if(k>0 && !current)
    return; //throw OutOfBounds();
	
	linkednode<T>* newnode = new linkednode<T>();
	newnode->data = x;  
    
    if(k){
    	newnode->link = current->link;
    	current->link = newnode;
    }
    else if(head == 0){
    	head = newnode;
    	head->link = NULL;
    }
    else{
    	newnode->link=head;
    	head = newnode;
    }
	return *this;
}

/*-----------------------------------*/
template <class T>
int linkedlist<T>::length()const{
int len = 0;
linkednode<T>* current = head;
while(current){
	len++;
	current = current->link;
return len;
}
}

/*-------------------------------------------------*/
template<class T>
linkedlist<T>& linkedlist<T>::Delete(int k,T & x){
if(k < 1)return;

linkednode<T>& p = head;
linkednode<T>* q = new linkednode<T>();

if(k>1){
	for(int i = 1; i < k-1 && p;i++) p = p->link;

if(!p)return;

q = p -> link;

if(q){
p->link = q->link;
delete q;
}
else{
	return; //throw OutOfBounds();
}
}

if(k == 1){
head = head->link;
delete p;
delete q;
}
return *this;
}


/*-----------------------------------*/
template<class T>
bool linkedlist<T>::find(int k, T & x){
//checkIndex(k);
linkednode<T>* p = head;
for(int i =1; i < k&& p;i++)p = p->link;

if(!p && p->data == x) return true;
return false;
}


/*--------------------------------*/
int linkedlist<T>:: search(int k, T & x){

linkednode<T>* p = head;
int i = 1;
while(p && ){
if(p->data == x)return i;
i++;
}
return -1;
}
	









