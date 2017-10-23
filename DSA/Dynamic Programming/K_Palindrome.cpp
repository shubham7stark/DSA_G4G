/*You are required to complete this function*/
bool yo(string s,int start,int end,int k){
     if(k<0)return false;
     if(k>=(end-start))return true;
     else if(s[start]==s[end])return yo(s,start+1,end-1,k);
     else return yo(s,start+1,end,k-1)||yo(s,start,end-1,k-1);
}
bool is_k_pallin(string s,int k)
{
   //return yo(s,0,s.size()-1,k);

    string a = "";
    int n = s.size();
    for(int i = 0 ; i < n ; i++){
        a += s[n-(i+1)];
    }
    int l[n+1][n+1];
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < n+1 ; j++){
            if(i==0 || j==0){
                l[i][j] = 0 ;
            }else{
                if(a[i-1] == s[j-1]){
                    l[i][j] = l[i-1][j-1] + 1;
                }else{
                    l[i][j] = max(l[i-1][j],l[i][j-1]);
                }
            }
        }
    }
    if(n-l[n][n] > k){
        return false;
    }else{
        return true;
    }
}
