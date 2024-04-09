#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* next;
    int vertex;
}node;
int visited[20];
node* G[20];
int n;
void insert(int vi,int vj){
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    if(G[vi]==NULL)
    G[vi]=q;
    else{
        p=G[vi];
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=q;
    }
}
void readgraph(){
    int ne,vi,vj;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        G[i]=NULL;
    }
    printf("Enter the number of edges: ");
    scanf("%d",&ne);
    for(int i=0;i<ne;i++){
        printf("Enter the node numbers : ");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
    }
}

void DFS(int i){
    node *p;
    visited[i]=1;
    printf("\n%d",i);
    for(p=G[i];p;p=p->next){
        if(!visited[p->vertex]){
            DFS(p->vertex);
        }
    }
}
void BFS(int i){
    int queue[20],front=-1,rear=-1,v;
    queue[++rear]=i;
    node *p;
    visited[i]=1;
    printf("\n%d",i);
    while(front!=rear){
        v=queue[front++];
        for(p=G[v];p;p=p->next){
            if(!visited[p->vertex]){
                queue[++rear]=p->vertex;
                visited[p->vertex]=1;
                printf("\n%d",p->vertex);
            }
        }
    }
}
int main(){
    int ch,item;
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                readgraph();
                break;
            case 2:
                printf("Enter the node to start traversal : ");
                scanf("%d",&item);
                for(int i=0;i<n;i++){
                    visited[i]=0;
                }
                DFS(item);
                break;
            case 3:
                printf("Enter the node to start traversal : ");
                scanf("%d",&item);
                for(int i=0;i<n;i++){
                    visited[i]=0;
                }
                BFS(item);
                break;
            case 4:
                exit(0);

        }
    }
}