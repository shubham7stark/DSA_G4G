#include<iostream>

using namespace std;


int findmaj(int A[], int size)
{
int maj = 0;
int i;
int count = 0;
for(i = 0; i < size; i ++){
   if(A[maj] == A[i]){
    count++;
   }
   else{
   	count--;
   }
   
   if(count == 0)
   {
   	maj  = i;
   	count = 1;
   }
}
return A[maj];
}

bool ismajority(int A[], int cand, int n){
int i ;
int count = 0;
 for(i = 0; i < n; i++)
	if(A[i] == cand)
	count ++;  
	
if(count >= n/2)
return true;
else return false;	
}

void printMajority(int A[] , int size){
	int a = findmaj(A,size);

   if(ismajority(A,a,size))
   cout << "Yes dud"<<endl;
   else
   cout << "No dude"<<endl;

}


int main()
{
	
int a[] = {1, 3, 3, 3, 2};
    printMajority(a, 5);
    return 0;	
	
	
	
}
