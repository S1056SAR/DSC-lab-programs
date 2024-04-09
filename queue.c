#include<stdio.h>
#include<stdlib.h>
typedef struct queue* queueptr;
typedef struct{
    int key;
}element;
struct queue{
    element data;
    queueptr link;
};
queueptr front=NULL;
queueptr rear=NULL;
void insert(element item){
    queueptr temp;
    temp=(queueptr)malloc(sizeof(struct queue));
    temp->data=item;
    temp->link=NULL;
    if(front==NULL)
    front=temp;
    else
    rear->link=temp;
    rear=temp;
}
element delete(){
    queueptr temp;
    element item;
    if(front==NULL){
        item.key=-1;
        return item;
    }
    else{
        temp=front;
        item=temp->data;
        front=front->link;
        free(temp);
        return item;
    }
}
void display(){
    queueptr temp;
    temp=front;
    if(temp==NULL){
        printf("\nQueue is empty");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data.key);
            temp=temp->link;
        }
    }

}
int main(){
    element item;int num,ch;
    while(1){
        printf("\n1:Insert\n2:Delete\n3:Display\n4:exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the number to be inserted : ");
                scanf("%d",&num);
                item.key=num;
                insert(item);
                break;
            case 2:
                item=delete();
                if(item.key==-1){
                    printf("\nNo elements present to be deleted");
                }
                else{
                    printf("\nPopped element : %d",item.key);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong choice");
                break;
        }
    }
    return 0;
}