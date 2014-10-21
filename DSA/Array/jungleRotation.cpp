#include<iostream>

using namespace std;

int rotate(int arr[], int d, int n){

for(int i = 0; i < d; i++){
	
	int k = arr[i];
	int j = i;
	
	while(j+d < n){
	arr[j] = arr[j+d];
	j += d;
	}
	arr[j] = k;
	
	for(int i = 0; i < 10 ; i++)cout << arr[i] << "  ";
	cout <<endl;
}

}

int main(){
	
	int ar[10] = {1,6,12,16,28,46,49,56,58,69};
	
	rotate(ar,3,10);
	
	for(int i = 0; i < 10 ; i++)cout << ar[i] << "  ";

}


