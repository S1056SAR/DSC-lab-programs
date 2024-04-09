#include<stdio.h>
#include<stdlib.h>
typedef struct tree* treeptr;
struct tree{
    treeptr rlink;
    treeptr llink;
    int data;
};
void insert(treeptr *root,int item){
    if((*root)==NULL){
        (*root)=(treeptr)malloc(sizeof(struct tree));
        (*root)->llink=NULL;
        (*root)->rlink=NULL;
        (*root)->data=item;
        return;
    }
    else if((*root)->data>item)
        insert(&(*root)->llink,item);
    else if((*root)->data<item)
        insert(&(*root)->rlink,item);
}
void inorder(treeptr root){
    if(root){
        inorder(root->llink);
        printf("%d\t",root->data);
        inorder(root->rlink);
    }
}
void postorder(treeptr root){
    if(root){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t",root->data);
    }
}
void preorder(treeptr root){
    if(root){
        printf("%d\t",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
int main(){
    treeptr root;
    root=NULL;
    int item,ch;
    while(1){
        printf("\n1:insert\n2.inorder\n3.postorder\n4.preorder\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter which element to be inserted : ");
                scanf("%d",&item);
                insert(&root,item);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                exit(0);

        }
    }
}