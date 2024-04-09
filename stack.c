#include <stdio.h>
#include <stdlib.h>
typedef struct stack *stackptr;
typedef struct
{
    int key;
} element;

struct stack
{
    element data;
    stackptr link;
};
stackptr top = NULL;
void push(element item)
{
    stackptr temp;
    temp = (stackptr)malloc(sizeof(struct stack));
    temp->data = item;
    temp->link = top;
    top = temp;
}
element pop()
{
    element item;
    if (top == NULL)
    {
        item.key = -1;
        return item;
    }
    else
    {
        item = top->data;
        top = top->link;
        return item;
    }
}
void display()
{
    stackptr temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data.key);
        temp = temp->link;
    }
}
int main()
{
    element item;int num;
    while (1)
    {
        int ch;
        printf("\n 1:Insert 2:pop 3.disply : ");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the number to pushed : ");
            scanf("%d", &num);
            item.key = num;
            push(item);
            break;
        case 2:
            item=pop();
            if(item.key==-1){
                    printf("\nUnderflow");
            }
            else
            printf("\nPopped element is : %d",item.key);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
            break;
            }
    }
    return 0;
}
