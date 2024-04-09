#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef struct{
    int key;
}element;

element heap[MAX_SIZE];
void insert(element item,int *n){
    if((*n)==MAX_SIZE-1){
        printf("Heap full");
        return;
    }
    int i;
    i=++(*n);
    while(i!=1 && item.key>heap[i/2].key){
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=item;
}
element delete(int *n){
    int parent,child;
    element temp,item;
    if((*n)==0){
        item.key=-1;
        return item;
    }
    item=heap[1];
    temp=heap[(*n)--];
    parent=1;
    child=2;
    while(child<=(*n)){
        if(child<(*n)&& heap[child].key<heap[child+1].key)
        child++;
        if(temp.key>heap[child].key)
        break;
        heap[parent]=heap[child];
        parent=child;
        child=child*2;
    }
    heap[parent]=temp;
    return item;
    

}
void display(int n){
    for(int i=1;i<=n;i++){
        printf("%d\t",heap[i].key);
    }
}
int main(){
    int ch;int n=0;
    element item;
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter the element to be inserted : ");
                scanf("%d",&item.key);
                insert(item,&n);
                break;
            case 2:
                item=delete(&n);
                if(item.key!=-1){
                    printf("\nItem deleted : %d",item.key);

                }
                break;
            case 3:
                display(n);
                break;
            case 4:
                exit(0);
        }
    }
}