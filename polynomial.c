#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int coeff;
    int pow;
    struct link* next;
}mypoly;
void mypoly_create(mypoly**);
void mypoly_show(mypoly *);
void mypoly_add(mypoly **,mypoly *,mypoly *);
int main(){
    mypoly *poly1,*poly2,*poly3;int ch;
    do{
        printf("Enter the first polynomial : ");
        mypoly_create(&poly1);
        printf("\nThe first polynomial");
        mypoly_show(poly1);
        printf("\nEnter the second polynomial");
        mypoly_create(&poly2);
        printf("\nsecond polynomial: ");
        mypoly_show(poly2);
        mypoly_add(&poly3,poly1,poly2);
        printf("\nThe result is :");
        mypoly_show(poly3);
        printf("\nDo you want to enter 2 more polynomials : ");
        scanf("%d",&ch);
    }while(ch);
    return 0;
}
void mypoly_create(mypoly** node){
    int flag;
    int coeff;
    int pow;
    mypoly* temp;
    temp=(mypoly*)malloc(sizeof(mypoly));
    *node=temp;
    do{
        printf("Enter the coefficient : ");
        scanf("%d",&coeff);
        temp->coeff=coeff;
        printf("Enter the exponent : ");
        scanf("%d",&pow);
        temp->pow=pow;
        temp->next=NULL;
        printf("Do you want to enter more terms : 0 or 1");
        scanf("%d",&flag);
        if(flag){
            temp->next=(mypoly*)malloc(sizeof(mypoly));
            temp=temp->next;
            temp->next=NULL;
        }
    }while(flag);
}
void mypoly_show(mypoly* node){
    while(node!=NULL){
        printf("%dx^%d",node->coeff,node->pow);
        node=node->next;
        if(node!=NULL){
            printf("+");
        }
    }
}
void mypoly_add(mypoly** result,mypoly* poly1,mypoly* poly2){
    mypoly* temp;
    temp=(mypoly*)malloc(sizeof(mypoly));
    temp->next=NULL;
    *result=temp;
    while(poly1 && poly2){
        if(poly1->pow>poly2->pow){
            temp->coeff=poly1->coeff;
            temp->pow=poly1->pow;
            poly1=poly1->next;
        }
        else if(poly2->pow>poly1->pow){
            temp->coeff=poly2->coeff;
            temp->pow=poly2->pow;
            poly2=poly2->next;
        }
        else{
            temp->pow=poly1->pow;
            temp->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        if(poly1 && poly2){
            temp->next=(mypoly*)malloc(sizeof(mypoly));
            temp=temp->next;
            temp->next=NULL;
        }
    }
    while(poly1 || poly2){
        temp->next=(mypoly*)malloc(sizeof(mypoly));
        temp=temp->next;
        temp->next=NULL;
        if(poly1){
            temp->coeff=poly1->coeff;
            temp->pow=poly1->pow;
            poly1=poly1->next;
        }
        if(poly2){
            temp->coeff=poly2->coeff;
            temp->pow=poly1->pow;
            poly2=poly2->next;
        }
    }
    printf("Addition complete");

}