#include<iostream>

using namespace std;

int getOcc(int a[], int n){
	
	int count = 0; 
	int i;
	for(i =0;i <n ;i ++){
	count = count^a[i];	
	}
	return count;
}
int main()
{
     int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d", getOcc(ar, n));
     return 0;
}
