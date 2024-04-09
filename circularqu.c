#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int data;
}element;
element* queue;
int front=0,rear=0,capacity;
void copy(element* start,element* end,element* newqueue){
    element *i,*j;
    j=start;
    i=newqueue;
    for(;j<end;j++,i++){
        *i=*j;
    }
}
void queueFull(){
    element* newqueue;
    newqueue=(element*)malloc(2*capacity*(sizeof(element)));
    int start=(front+1)%capacity;
    if(start<2)
    copy(queue+start,queue+start+capacity-1,newqueue);
    else{
        copy(queue+start,queue+capacity-1,newqueue);
        copy(queue,queue+rear+1,newqueue+capacity-start);
    }
    front=2*capacity-1;
    rear=capacity-1;
    capacity*=2;
    free(queue);
    queue=newqueue;
}
void insert(element item){
    rear=(rear+1)%capacity;
    if(front==rear){
        queueFull();
    }
    queue[rear]=item;
}
element delete(){
    element item;
    if(front==rear){
        item.data=-1;
        return item;
    }
    front=(front+1)%capacity;
    return queue[front];
}
void display(){
    int i;
    if(front==rear){
        printf("No elements");
        return ;
    }
    else{
        for(i=(front+1)%capacity;i!=rear;i=(i+1)%capacity){
            printf("%d\t",queue[i].data);
        }
        printf("%d",queue[i].data);
        printf("\n");
    }
}
int main(){
    element item;
    int ch;
    printf("\nEnter the capacity : ");
    scanf("%d",&capacity);
    queue=(element*)malloc(capacity*sizeof(element));
    while(1){
        printf("\nEnter the choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("\nEnter the element to be inserted : ");
                scanf("%d",&item.data);
                insert(item);
                break;
            case 2:
                item=delete();
                if(item.data==-1){
                    printf("\nno element to be deleted");
                    break;
                }
                else{
                    printf("\nDeleted element : %d",item.data);
                }
                break;
            case 3:
                display();
                break;
            case 4: 
                exit(0);
                break;
        }
    }
}