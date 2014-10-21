#include<iostream>
using namespace std;


void exchange(int*a, int * b){
	int c = *a;
	*a = *b;
	*b = c;
}

int partition(int A[], int a, int z){
	int pivot = A[a];
	
	int i = a+1;
	int j;
	
	for(j = a+1; j <= z ; j++)
	{
		if(A[j] <= pivot ){
		exchange(&A[i],&A[j]);
 		i++;
		}
	}
	exchange(&A[i-1], &A[a]);

return (i);
}

void quicksort(int A[], int a, int z){
	int b;

   if(a < z){
    b = partition(A,a,z);
 cout << b <<"pivott"<<endl;	
	quicksort(A,a,b-1);
	quicksort(A,b+1,z);
   
   }

}


bool hasArray(int A[], int size, int sum){

cout << endl<<"Yes"<< endl;	
	quicksort(A, 0, size-1);


    for(int qw =0; qw< size; qw++){
	cout << A[qw] << endl;
	
	}
	
	int l = 0;
	int r = size - 1;
	
	while(l<=r){
	if(A[l] + A[r] == sum) return 1;
	else if(A[l] + A[r] <= sum) l++;
	else if(A[l] + A[r] >= sum) r--;
	}
	
	return 0;
	
}



int main(){
 int A[] = {1, 4, 45, 6, 10, -8};
    int n = 16;
    int arr_size = 6;
    
    if( hasArray(A, arr_size, n))
        printf("Array has two elements with sum 16");
    else
        printf("Array doesn't have two elements with sum 16 ");
 
    getchar();
    return 0;	
	
}


