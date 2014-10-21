#include<iostream>
using namespace std;

void printpairs(int A[], int size ,int sum)
{

int i,temp;
bool heapbin[100000] = {0};

for(i = 0; i <= size; i++){
	temp = sum - A[i];
	if(temp >= 0 && heapbin[temp] == 1){
    cout << "here we r done"<< endl;
	return;
	}
	heapbin[A[i]] = 1;	
}
}

int main(){
	
	int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = 6;
 
    printpairs(A, arr_size, n);
 
    getchar();
    return 0;
}



