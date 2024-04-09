#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nfind(char* str,char* pat){
    int i,j,start=0;
    int lasts=strlen(str)-1;
    int lastp=strlen(pat)-1;
    int endmatch=lastp;
    for(i=0;endmatch<lasts;endmatch++,start++){
        if(str[endmatch]==pat[lastp]){
            for(j=0,i=start;j<lastp && str[i]==pat[j];i++,j++);
            if(j==lastp)
            return start;
        }
        
    }
    return -1;
    
}
int KMP(char *str,char* pat,int* failure){
    int i=0,j=0;
    int lens=strlen(str)-1;
    int lenp=strlen(pat)-1;
    while(i<lens && j<lenp){
        if(str[i]==pat[j]){
            i++;
            j++;
        }
        else if(j==0){
            i++;
        }
        else
        j=failure[j-1]+1;
    }
    return ((j==lenp)?(i-lenp):-1);
}
void fail(char* pat,int* failure){
    int i,j;
    int n=strlen(pat);
    failure[0]=-1;
    for(int j=1;j<n;j++){
        i=failure[j-1];
        while(i>=0 && pat[j]!=pat[i+1])
        i=failure[i];
        if(pat[j]==pat[i+1])
        failure[j]=i+1;
        else
        failure[j]=-1;
    }
}
int main(){
    char str[1000],pat[1000];
    printf("Enter the string :");
    scanf("%s",str);
    printf("Enter the pattern:");
    scanf("%s",pat);
    int nf=nfind(str,pat);
    if(nf==-1)
    printf("Substring not present");
    else
    printf("substring found at %d",nf);
    int failure[strlen(pat)];
    fail(pat,failure);
    int kmp=KMP(str,pat,failure);
    if(kmp==-1)
    printf("\nNot found");
    else
    printf("\nFound at %d",kmp);
    return 0;

}