#include<iostream>
using namespace std;
int merging(int arr1[], int arr2[], int n){

int m1 = -1,  m2 = -1;
int i =0,j=0;

for(int count =0; count < n; count++)
{
	

if(i == n){
m1 = m2;
m2 = arr2[0];
break;	
}
else if(j == n){
m1 = m2;
m2 = arr1[0];
break;	
}


if(arr1[i] > arr2[j]){
m1 = m2;
m2 = arr1[i];
j++;
}
else{
m1 = m2;
m2 = arr2[j];
i++;	
}

}
return (m1+m2)/2;
}


/* Driver program to test above function */
int main(){
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
 
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    
	if (n1 == n2)
        cout << "Median is" << merging(ar1, ar2, n1) <<endl;
    else
        cout << "Doesn't work for arrays of unequal size" <<endl;
    getchar();
   
    return 0;
}
