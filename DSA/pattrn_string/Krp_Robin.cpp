#include<stdio.h>
#include<string.h>
 
// d is the number of characters in input alphabet
#define d 256
void search(char *pat, char *txt, int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int p =0,t = 0;
    int i,j,h = 1;
    
    for(i =0; i < M-1;i++)
       h = (h*d)%q;
    
    for(i=0;i<M;i++){
    	p = (p*d + pat[i])%q;
    	t = (t*d + txt[i])%q;
    }
    
    i = 0;
    while(i <= N-M){
    
	if(p == t){
		for(j=0; j < M;j++)
    	  if(pat[i+j] != txt[j])
    	     break;
		
		if(j == M)	  
		printf("Pattern found at index %d \n", i);
	
	}
	
    	if(i < M-N){
    		p = (d*(p - txt[i]*h) + txt[i+M] )%q;
    	    if(t < 0) 
              t = (t + q); 
		}
    i++;
	}
	
}
  
/* Driver program to test above function */
int main()
{
    char *txt = "GEEKS FOR GEEKS";
    char *pat = "GEEK";
    int q = 101;  // A prime number
    search(pat, txt, q);
    getchar();
    return 0;
}

