#include<iostream>

using namespace std;

int missing(int A[], int b){
	
	int x1 = A[0], x2 = 1;
	
	for(int i = 1; i < b; i++) 
	  x1 ^= A[i];
	
	for(int i = 2; i < b+2; i++) 
	 x2 ^= i;
	
	return (x1^x2);

}


int main()
{
    int a[] = {1, 2, 4, 5, 6};
    
    int miss = missing(a, 5);
    printf("%d", miss);
    getchar();
}
