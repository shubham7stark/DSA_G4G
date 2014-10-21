#include<iostream>

using namespace std;
int getocc(int A[], int n)
{
int res = 0; 
int i;
for(i = 0; i<n; i ++){
	res += 1&A[i];
}
return res;
}

int main()
{
     int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d", getocc(ar, n));
     return 0;
}
