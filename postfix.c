#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum{lparen,rparen,plus,minus,times,divide,eos,operand}precedence;
int isp[]={0,19,12,12,13,13,0};
int icp[]={20,19,12,12,13,13,0};
precedence stack[30];
char expr[20];
void push(precedence token);
precedence pop();
precedence gettoken(char *symbol,int *n);
void print_token(precedence token);
void postfix();
int main(){
    printf("Enter the infix expression : ");
    scanf("%s",expr);
    postfix();
}
void push(precedence token){
    if()
}