#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int col;
    int row;
    int value;
}term;
term a[100],b[100];
void simple(term a[],term b[]){
    int numTerms=a[0].value;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].value=numTerms;
    if(numTerms>0){
        int currentb=1;
        for(int c=0;c<a[0].col;c++){
            for(int i=1;i<=numTerms;i++){
                if(c==a[i].col){
                    b[currentb].row=a[i].col;
                    b[currentb].col=a[i].row;
                    b[currentb].value=a[i].value;
                    currentb++;

                }
            }
        }
    }
}
void fast(term a[],term b[]){
    int rowTerms[a[0].col],startingPos[a[0].col];int i,j;
    int numTerms=a[0].value;
    int numCols=a[0].col;
    b[0].row=numCols;
    b[0].col=a[0].row;
    b[0].value=numTerms;
    if(numTerms>0){
        for(i=0;i<numCols;i++)
        rowTerms[i]=0;
        for(i=1;i<=numTerms;i++)
        rowTerms[a[i].col]++;
        startingPos[0]=1;
        for(i=1;i<numCols;i++)
        startingPos[i]=startingPos[i-1]+rowTerms[i-1];
        for(i=1;i<=numTerms;i++){
            j=startingPos[a[i].col]++;
            b[j].col=a[i].row;
            b[j].row=a[i].col;
            b[j].value=a[i].value;
        }
    }
}
int main(){
    printf("\nEnter the number of rows columns and values : ");
    scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].value);
    for(int i=1;i<=a[0].value;i++){
        printf("\nEnter the row,col and value:  ");
        scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
    }
    printf("\nsparse matrix : ");
    for(int i=1;i<=a[0].value;i++)
    printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
    term b[100];
    simple(a,b);
    printf("\nSimple transpose");
    for(int i=1;i<=a[0].value;i++)
    printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
    term c[100];
    fast(a,c);
    printf("\nFast transpose");
    for(int i=1;i<=a[0].value;i++)
    printf("%d\t%d\t%d\n",c[i].row,c[i].col,c[i].value);
}