#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int vertex;
    struct node* next;
}node;
int visited[20];
node *G[20];
int n;
void readgraph();
void insert(int vi,int vj);
void DFS(int i);
void BFS(int i);
int main(){
    int ch,item;
    while(1){
        printf("\n1.insert\n2.DFS\n3.BFS\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                readgraph();
                break;
            case 2:
                printf("Enter the element to begin: ");
                scanf("%d",&item);
                for(int i=0;i<n;i++)
                visited[i]=0;
                DFS(item);
                break;
            case 3:
                printf("Enter the element to begin: ");
                scanf("%d",&item);
                for(int i=0;i<n;i++)
                visited[i]=0;
                BFS(item);
                break;
            case 4:
                exit(0);

        }
    }
}
void readgraph(){
    int vi,vj,ne;
    printf("\nEnter the number of nodes to be inserted : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    G[i]=NULL;
    printf("\nEnter the number of vertices");
    scanf("%d",&ne);
    for(int i=0;i<ne;i++){
        printf("Enter the vi and vj : ");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
        insert(vj,vi);
    }
}
void insert(int vi,int vj){
    node *p,*q;
    q=(node*)malloc(sizeof(struct node));
    q->vertex=vj;
    q->next=NULL;
    if(G[vi]==NULL){
        G[vi]=q;
        return ;
    }
    else{
        p=G[vi];
        while(p->next!=NULL)
        p=p->next;
        p->next=q;

    }
}
void DFS(int i){
    node *p;
    visited[i]=1;
    printf("%d\n",i);
    for(p=G[i];p;p=p->next){
        if(visited[p->vertex]==0)
        DFS(p->vertex);
    }
}
void BFS(int i){
    node *p;
    int queue[20],front=-1,rear=-1,v;
    queue[++rear]=i;
    visited[i]=1;
    printf("%d\n",i);
    while(front!=rear){
        v=queue[++front];
        for(p=G[v];p;p=p->next){
            if(!visited[p->vertex]){
                queue[++rear]=p->vertex;
                printf("%d\n",p->vertex);
                visited[p->vertex]=1;
            }
        }
    }
}