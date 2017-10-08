bool my(struct val a,struct val b){
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,my);
    int A[n]={1};
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].second<p[i].first&&A[i]<A[j]+1)
            A[i]=A[j]+1;
        }        
    }
    int max=1;
    for(int i=0;i<n;i++){
        if(max<A[i])max=A[i];
    }
    return max;
}
