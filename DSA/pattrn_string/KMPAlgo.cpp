#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void computeLPS(char*pat,int M,int* lps){
	int i,len = 0;
    lps[0] = 0;
    i =1;
    
    while(i < M){
     
	 if(pat[i] == pat[len]){
     	len++;
        lps[i] = len;
        i++;
	}	
    else{
    
	 if(len != 0){
	 	len = lps[len-1];
	 }
	 else{
	 	lps[i] = 0;
	 	i++;
	 }
    
	}
    
	}

}


void KMPSearch(char*pat, char*txt){
int M = strlen(pat);
int N = strlen(txt);

int *lps = (int *)malloc(M*sizeof(int));
int j =0;

computeLPS(pat,M,lps);
int i = 0;

while(i < N){
	if(pat[j] == txt[i]){
		i++;j++;
	}
	if(j == M){
		printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
	}
	else if(pat[j] != txt[i]){
		if(j != 0){
		  j = lps[j-1];	
		}else 
		i++;
	}
	
}
free(lps);
}


// Driver program to test above function
int main()
{
	char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   KMPSearch(pat, txt);

   return 0;
}

