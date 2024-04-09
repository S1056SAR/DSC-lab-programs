#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
int icp[]={20,19,12,12,13,13,13,0};
int isp[]={0,19,12,12,13,13,13,0};
precedence stack[30];
char EXPR[MAX_SIZE];
int top=-1;
void push(precedence token){
    if(top>MAX_SIZE-1){
        printf("Stack full");
        return;
    }
    stack[++top]=token;
}
precedence pop(){
    if(top==-1){
        printf("Underflow");
        exit(0);
    }
    return stack[top--];
}
precedence get_token(char *symbol,int *n){
    *symbol=EXPR[(*n)++];
    switch(*symbol){
        case '(':return lparen;
        case ')':return rparen;
        case '+':return plus;
        case '-':return minus;
        case '*':return times;
        case '/':return divide;
        case '%' :return mod;
        case '\0':return eos;
        default:return operand;
    }
}
void print_token(precedence token){
    switch(token){
        case plus:printf("+");break;
        case minus:printf("-");break;
        case times:printf("*");break;
        case divide:printf("/");break;
        case mod:printf("%%");break;
    }
}
void postfix(){
    char symbol;
    precedence token;
    int n=0;
    stack[0]=eos;
    top=0;
    for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n)){
        if(token==operand)
        printf("%c",symbol);
        else if(token==rparen){
            while(token!=lparen){
                print_token(pop());
            }
            pop();
        }
        else{
            while(isp[stack[top]]>=icp[token]){
                print_token(pop());
            }
            push(token);
        }
    }
    while((token=pop())!=eos){
        print_token(token);
}
}
int main(){
    printf("enter the string : ");
    scanf("%s",EXPR);
    postfix();
    return 0;
}