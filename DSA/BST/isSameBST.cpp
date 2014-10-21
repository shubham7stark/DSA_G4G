#include <stdio.h>
#include<limits.h>
#include<stdbool.h>

bool isSameBST(int* arr1,int* arr2,int n, int a1, int a2, int min, int max){
	int i,j;
	for(i=a1;i<n;i++)
	if(arr1[i] < max && arr1[i] > min)break;
	
	for(j=a2;j <n;j++)
	if(arr2[j] < max && arr2[j] > min)break;
	
	
	if(i == n && j == n)
	return true;

	if((i==n)^(j==n) || arr1[i] != arr2[j])
      return false;

  return isSameBST(arr1,arr2,n,i+1,j+1,min,arr1[i]) 
        && isSameBST(arr1,arr2,n,i+1,j+1,arr1[i],max);
 
}

int main()
{
   int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n=sizeof(a)/sizeof(a[0]);
   printf("%s\n", isSameBST(a, b, n,0,0,INT_MIN,INT_MAX)?
             "BSTs are same":"BSTs not same");
   return 0;
}
