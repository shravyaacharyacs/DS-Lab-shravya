#include<stdio.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];

}
int precedence(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    return 0;

}
void InfixtoPostfix(char const* exp){
    for(int i=0;exp[i]!='\0';i++){
        if(isspace(exp[i])) continue;
        if(isalnum(exp[i])){
            printf("%c",exp[i]);
        }else if(exp[i]=='('){
                 push(exp[i]);
        }else if(exp[i]==')'){
            while(top>=0 && stack[top]!='('){
                printf("%c",pop());
            }
            pop();

        }else{
            if(top>=0 && precedence(stack[top])>=precedence(exp[i])){
                printf("%c",pop());
            }
            push(exp[i]);


        }
    }
    while(top>=0){
        printf("%c",pop());
    }

}
void main(){
    char exp[MAX];
    printf("Infix:");
    fgets(exp,sizeof(exp),stdin);
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='^' || exp[i]=='%' || exp[i]=='$' || exp[i]=='#' ){
            printf("Invalid expression \n");
            return;
        }
    }

    printf("postfix:");
    InfixtoPostfix(exp);

}

