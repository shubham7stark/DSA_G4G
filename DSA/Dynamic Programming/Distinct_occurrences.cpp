/*You are required to complete this method*/
int subsequenceCount(string S, string T)
{
    int n=S.size();
    int m=T.size();
    if(n<m)return 0;
  int a[m+1][n+1];
  for(int i=0;i<=n;i++){
     a[0][i]=1; 
  }
  for(int i=0;i<=m;i++){
     a[i][0]=0; 
  }
  a[0][0]=1;
  for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
          if(T[i-1]==S[j-1])a[i][j]=a[i][j-1]+a[i-1][j-1];
          else a[i][j]=a[i][j-1];
      }
  }
  return a[m][n];
}
 
