#include<iostream>
using namespace std;


void rotate(int arr[], int d, int n){
	
	int k = arr[d-1];
	
	for(int i = 0; i < d; i++){
	for(int j = 0; j < n; j++){
	   arr[(d-1-i+j)%n] = arr[(d-i+j)%n];
     }
    }
    
	arr[n-1] = k;
}



int main(){
	
	int ar[10] = {1,6,12,16,28,46,49,56,58,69};
	
	rotate(ar,3,10);
	
	for(int i = 0; i < 10 ; i++)cout << ar[i] << "  ";
}
