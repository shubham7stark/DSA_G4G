#include<iostream>

using namespace std;



int maxSubArraySum(int a[], int n){
	int p=0, q =0;
	int i;
	for(i = 0; i < n ;i ++){
	q = q + a[i];
	
	if(q<0)q=0;
	if(p<q) p =q ;
	
	}
	
	return p;
}

int main()
{
   int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   getchar();
   return 0;
}
