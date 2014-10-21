#include<iostream>

using namespace std;


void reverse(int arr[], int start, int end)
{
	while(start < end){
	int k = arr[start];
	arr[start] = arr[end];
	arr[end] = k;	start++;end--;
	} 
	
}

void rotateleft(int arr[], int d, int n){

reverse(arr, 0, d-1);
reverse(arr, d, n-1);
reverse(arr, 0 , n-1);
}

int main(){
	
	int ar[10] = {1,6,12,16,28,46,49,56,58,69};
	
	rotateleft(ar,3,10);
	
	for(int i = 0; i < 10 ; i++)cout << ar[i] << "  ";
}
