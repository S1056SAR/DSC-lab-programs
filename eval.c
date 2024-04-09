#include<stdio.h>
#include<stdlib.h>
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
int stack[30];
char EXPR[30];
int top=-1;
void push(int item){
    stack[++top]=item;
}
int pop(){
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
        case '\0':return eos;
        default:return operand;

    }
}
int postfix(){
    int op1,op2,n=0;
    char symbol;
    precedence token;
    for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n)){
        if(token==operand){
            push(symbol-'0');
        }
        else{
            op2=pop();
            op1=pop();
            switch(token){
                case plus:
                push(op1+op2);
                break;
                case minus:
                push(op1-op2);
                break;
                case times:
                push(op1*op2);
                break;
                case divide:
                push(op1/op2);
                break;
                case mod:
                push(op1%op2);
                break;
            }
        }
    }
    return pop();
}
int main(){
    printf("Enter the expression : ");
    scanf("%s",EXPR);
    int ch=postfix();
    printf("%d",ch);
}