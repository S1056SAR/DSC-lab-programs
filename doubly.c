#include <stdio.h>
#include <stdlib.h>
typedef struct node *nodepointer;
typedef struct node
{
    nodepointer rlink;
    int data;
    nodepointer llink;
} node;
void dinsert(nodepointer node, nodepointer newnode)
{
    newnode->rlink = node->rlink;
    newnode->llink = node;
    if (node->rlink != NULL)
    {
        node->rlink->llink = newnode;
    }
    node->rlink = newnode;
}
void ddelete(nodepointer current)
{
    if (current->llink != NULL)
        current->llink->rlink = current->rlink;
    if (current->rlink != NULL)
        current->rlink->llink = current->llink;
    free(current);
}
void display(nodepointer header)
{
    nodepointer current = header->rlink;
    if (current == NULL)
    {
        printf("No value");
        return;
    }
    else
    {
        while (current != NULL)
        {
            printf("%d\t", current->data);
            current = current->rlink;
        }
    }
}
int main()
{
    nodepointer header;
    header = (nodepointer)malloc(sizeof(node));
    header->rlink = NULL;
    header->llink = NULL;
    int ch;
    int item;
    while (1)
    {
        printf("\n1:insert 2: delete 3:display\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted");
            scanf("%d", &item);
            nodepointer newnode;
            newnode = (nodepointer)malloc(sizeof(node));
            newnode->data = item;
            dinsert(header, newnode);
            break;
        case 2:
            if (header->rlink == NULL)
            {
                printf("\nNo element to be deleted");
                break;
            }

            printf("Enter the element to be deleted :");
            scanf("%d", &item);
            nodepointer current;
            current = header->rlink;
            while (current != NULL && current->data != item)
            {
                current = current->rlink;
            }

            if (current == NULL)
                printf("element is not present");
            else
            {
                ddelete(current);
                printf("Element deleted");
            }
            break;

        case 3:
            display(header);
            break;
        case 4:
            free(header);
        case 5:
            exit(0);
        }
    }
}