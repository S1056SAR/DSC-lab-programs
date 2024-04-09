#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int nfind(char* str,char* pat){
    int i,j,start=0;
    int lasts=strlen(str)-1;
    int lastp=strlen(pat)-1;
    int endmatch=lastp;
    for(i=0;endmatch<lasts;endmatch++,start++){
        if(str[endmatch]==pat[lastp]){
            for(j=0,i=start;j<lastp && str[i]==pat[j];i++,j++);
            if(j==lastp){
                return start;
            }
        }
    }
    return -1;
}
int kmp(char* str,char* pat,int* failure){
    int i=0,j=0;
    int lens=strlen(str);
    int lenp=strlen(pat);
    while(i<lens && j<lenp){
        if(str[i]==pat[j]){
            i++;
            j++;
        }
        else if(j==0){
            i++;
        }
        else{
            failure[j]=failure[j-1]+1;
        }
    }
    return ((j==lenp)?(i-lenp):-1);
}
void fail(char* pat,int* failure){
    int i,j,n=strlen(pat);
    failure[0]=-1;
    for(j=1;j<n;j++){
        i=failure[j-1];
        while(pat[j]!=pat[i+1]&& i>=0)
        i=failure[i];
        if(pat[j]==pat[i+1]){
            failure[j]=i+1;
        }
        else 
        failure[j]=-1;
    }

}
int main(){
    char str[100],pat[100];
    printf("Enter the string : ");
    scanf("%s",str);
    printf("Enter the pattern : ");
    scanf("%s",pat);
    int failure[strlen(pat)];
    int nf=nfind(str,pat);
    fail(pat,failure);
    int km=kmp(str,pat,failure);
    if(nf==-1)
    printf("Pattern not present");
    else
    printf("Pattern found at %d",nf);
    if(km==-1)
    printf("\nPattern not present");
    else
    printf("\nPattern found at %d",km);
    return 0;

}