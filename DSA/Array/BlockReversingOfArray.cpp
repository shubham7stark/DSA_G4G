#include<iostream>

using namespace std;

void swap(int arr[], int fi, int si, int d){

for(int i = 0; i < d; i ++){
	int k = arr[fi+i];
	arr[fi + i] = arr[si + i];
	arr[si + i] = k;	
}

}


void rotate(int arr[], int d, int n){
	
	if(d==0 || n == 0)return;
	int  k = n - d;
	
	cout << k << d << n << endl; 

	if(n == 2*d){
		swap(arr,0,d,d);
	
	}
	
	else if(n > 2*d){
	swap(arr,0,n-d,d);
    rotate(arr,d,n-d);
	}
	
	else{
		swap(arr,0,d,k);
		rotate(arr+n-d,2*d-n,d);
		
   }
	
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   rotate(arr, 2, 7);

for(int i = 0; i < 7; i ++)
	cout << arr[i]<<"";

   getchar();
   return 0;
}    

