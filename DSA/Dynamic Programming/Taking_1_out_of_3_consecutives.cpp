#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int p=0;p<t;p++){
	    int n;
	    cin>>n;
	    vector<int> A(n);
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    int sum=0;
	    vector<int>b(n);
	    if(n==1)sum=A[0];
	    if(n==2)sum=min(A[0],A[1]);
	    if(n==3)sum=min(A[0],min(A[1],A[2]));
	    else{
	        b[0]=A[0];
	        b[1]=A[1];
	        b[2]=A[2];
	    }
	    for(int i=3;i<n;i++){
	        b[i]=A[i]+min(b[i-1],min(b[i-2],b[i-3]));
	        //cout<<b[i]<<endl;
	    }
	    if(n>3)sum=min(b[n-1],min(b[n-2],b[n-3]));
	    cout<<sum<<endl;
	}
	return 0;
}
