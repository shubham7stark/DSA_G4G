#include<iostream>
using namespace std;




/*---------------------------------------*/
int findpivot(int A[], int low , int high){
	
	if(low >high)return -1;
    if(high == low) return low;
  
   int mid = (high + low)/2;
   
   if(mid < high && A[mid] > A[mid+1]) return mid;
   if(mid > low && A[mid-1] > A[mid]) return (mid-1);
 
   if (A[low] >= A[mid])
   return findpivot(A, low, mid-1);
   else
   return findpivot(A, mid + 1, high);

}


int BinarySearch(int A[], int low, int high, int no){
	
	if(low > high)return -1;
	
	int mid = (high + low)/2;
	
	if(A[mid] == no)return mid;
	
	if(A[mid] > no)return BinarySearch(A, low, mid-1,no); 
	else return BinarySearch(A,mid+1,high,no);
	
}

int pivotedBinarySearch(int A[], int size, int no){

cout <<size << "size " <<endl;
int pivot = findpivot(A,0,size-1); 

if(pivot == -1)return BinarySearch(A,0,size-1,no);
if(A[pivot] == no)return pivot;
if(A[0] >  no) return BinarySearch(A,pivot+1,size -1,no);
else return BinarySearch(A,0,pivot-1,no); 
}


int main()
{
   // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int arr_size = sizeof(arr1)/sizeof(arr1[0]);
   int no = 3;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr1, arr_size, no));
 
 
    // Let us search 3 in below array
   int arr2[] = {3, 4, 5, 1, 2};
   arr_size = sizeof(arr2)/sizeof(arr2[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));
 
   // Let us search for 4 in above array
   no = 4;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));
 
   // Let us search 0 in below array
   int arr3[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
   no = 0;
   arr_size = sizeof(arr3)/sizeof(arr3[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr3, arr_size, no));
 
   // Let us search 3 in below array
   int arr4[] = {2, 3, 0, 2, 2, 2, 2, 2, 2, 2};
   no = 3;
   arr_size = sizeof(arr4)/sizeof(arr4[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));
 
   // Let us search 2 in above array
   no = 2;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));
 
   // Let us search 3 in below array
   int arr5[] = {1, 2, 3, 4};
   no = 3;
   arr_size = sizeof(arr5)/sizeof(arr5[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr5, arr_size, no));
 
   return 0;
}
