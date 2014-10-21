#include<iostream>
using namespace std;

void printSorted(int* arr,int inStart, int inEnd){
	if(inStart>inEnd)return;
	
	printSorted(arr,2*inStart + 1, inEnd);
	
	printf("%d %s", arr[inStart] , " ");
	printSorted(arr,2*inStart + 2, inEnd);
	 
}

int main()
{
  int arr[] = {4, 2, 5, 1, 3};
  int arr_size = sizeof(arr)/sizeof(int);
  printSorted(arr, 0, arr_size-1);
  getchar();
  return 0;
}
