#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
int choice,item;

void push(){
    if(top>=MAX-1){
    printf("The stack is full, stack overflow\n");
    return;
    }
    stack[++top]=item;
}
void pop(){
    if(top==-1){
    printf("The stack is empty, stack underflow\n");
    return;
    }
    printf("The popped item is %d\n",stack[top--]);
}
void display(){
    if(top==-1){
    printf("The stack is empty\n");
    return;
    }
    for(int i=top;i>=0;i--){
    printf("%d\n",stack[i]);
    }
}
void main(){

    while(1){
        printf("The options are \n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
        printf("choose your option\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter item to be pushed:\n");
                scanf("%d",&item);
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
    }
}
