#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct node{
    struct node* next;
    int vertex;
}node;
void create();
void insert(int vi,int vj);
void dfs(int i);
node *G[20];
int visited[MAX_SIZE];
int n;


int main(){
    int ch,i;
    do{
        printf("1:create\n2:bfs\n3:dfs");
        printf("\nEnter ur choice:");
        scanf("%d",&ch);
        switch(ch){
        case 1:
        create();break;
        case 2:
        for(i=0;i<n;i++)
        visited[i]=0;
        printf("Enter the starting node: ");
        int j;
        scanf("%d",&j);
        dfs(j);
        break;
        }
    }while(ch!=3);
}
void create(){
    int noofedges,vi,vj;
    printf("nEnter the no of vertices:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    G[i]=NULL;
    printf("\nEnter the number of edges :");
    scanf("%d",&noofedges);
    for(int i=0;i<noofedges;i++){
        printf("\nEnter the vertices which edges in b/w");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
        insert(vj,vi);
    }
}
void insert(int vi,int vj){
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    if(G[vi]==NULL){
        G[vi]=q;
    }
    else{
        p=G[vi];
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=q;
    }
}
void dfs(int i){
        visited[i]=1;
        printf("%d\n",i);
        node* p;
        for(p=G[i];p!=NULL;p=p->next){
            if(!visited[p->vertex])
            dfs(p->vertex);
        }
}