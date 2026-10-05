#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front =-1;
int rear =-1;
int queue[MAX];
void Insert(int item){
    if(rear==MAX-1){
        printf("The queue is full overflow \n");
        return;
    }
    if(front==-1){
        front=0;
    }

    rear++;
    queue[rear]=item;
}

void Delete(){
    if(front==-1 || front>rear){
        printf("The queue is empty Underflow \n");
        return;
    }
    printf("deleted element is %d\n",queue[front]);
    if(front>rear){
        front=-1;
        rear=-1;
    }
    front++;
}
void Display(){
    if(front==-1 || front>rear){
        printf("The queue is empty Underflow \n");
        return;
    }
    for(int i=front;i<rear;i++){
        printf("%d",queue[i]);
    }
}
int main(){
    int choice,value;
    while(1){
        printf("The operations of Queue\n");
        printf("1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter element\n");
            scanf("%d",&value);
            Insert(value);
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);

        }
    }

}
