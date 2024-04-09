#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int row;
    int col;
    int value;
}term;
void simple(term a[],term b[]){
    int numTerms=a[0].value;
    b[0].value=numTerms;
    b[0].col=a[0].row;
    b[0].row=a[0].col;
    if(numTerms>0){
        int currentb=1;
        for(int c=0;c<a[0].col;c++){
            for(int i=1;i<=numTerms;i++){
                if(a[i].col==c){
                    b[currentb].col=a[i].row;
                    b[currentb].row=a[i].col;
                    b[currentb].value=a[i].value;
                    currentb++;
                }
            }

        }

    }
}
void fast(term a[],term b[]){
    int startinpos[a[0].col],rowTerms[a[0].col];
    int numTerms=a[0].value,numCols=a[0].col,i,j;
    b[0].col=a[0].row;
    b[0].row=numCols;
    b[0].value=numTerms;
    if(numTerms>0){
        for(i=0;i<numCols;i++){
            rowTerms[i]=0;
        }
        for(i=1;i<=numTerms;i++){
            rowTerms[a[i].col]++;
        }
        startinpos[0]=1;
        for(i=1;i<numCols;i++)
        startinpos[i]=startinpos[i-1]+rowTerms[i-1];
        for(i=1;i<=numTerms;i++){
            j=startinpos[a[i].col]++;
            b[j].col=a[i].row;
            b[j].row=a[i].row;
            b[j].value=a[i].value;

        }

    }
}
term a[100];
term b[100];
int main(){
    printf("Enter the number of row,cols,terms : ");
    scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].value);
    for(int i=1;i<=a[0].value;i++){
        printf("Enter the rows , cols and value : ");
        scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
    }
    for(int i=1;i<=a[0].value;i++){
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
    }
    term b[100];
    simple(a,b);
    for(int i=1;i<=a[0].value;i++){
        printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
    }
    term c[100];
    fast(a,c);
    for(int i=1;i<=a[0].value;i++){
        printf("%d\t%d\t%d\n",c[i].row,c[i].col,c[i].value);
    }
    return 0;
}