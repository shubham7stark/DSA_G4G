#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
 {
	//code
int t;
cin>>t;
for(int p=0;p<t;p++){
    int n;
    cin>>n;
    vector<string>A(n);
    unordered_set<string> u;
    for(int i=0;i<n;i++){
        cin>>A[i];
        u.insert(A[i]);
    }
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.size();i++){
        string b=s.substr(count,i-count+1);
        //cout<<b<<endl;
        if(u.find(b)!=u.end())count=i+1;
    }
    if(count==s.size())cout<<1<<endl;
    else cout<<0<<endl;
    
}
	return 0;
}
