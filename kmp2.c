#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int nfind(char *str,char *pat){
    int i,j,lasts,lastp,endmatch,start;
    start=0;
    lasts=strlen(str)-1;
    lastp=strlen(pat)-1;
    endmatch=lastp;
    for(i=0;endmatch<lasts;start++,endmatch++){
        if(str[endmatch]==pat[lastp]){
            for(i=start,j=0;j<lastp && str[i]==pat[j];i++,j++);
            if(j==lastp)
            return start;
        }
    }
    return -1;
}
int main(){
    char str[100],pat[100];
    printf("Enter the string : ");
    scanf("%s",str);
    printf("Enter the pattern : ");
    scanf("%s",pat);
    int ch=nfind(str,pat);
    if(ch==-1)
    printf("pattern not present");
    else
    printf("patter found at %d",ch);
    return 0;
    

}