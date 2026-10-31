#include <stdio.h>

#define MAX 3 

int c_queue[MAX];
int c_front = -1, c_rear = -1;

void insertCircular(int item) {
    if ((c_rear + 1 == c_front) || (c_rear == MAX - 1 && c_front == 0)) {
        printf("\n Circular Queue Overflow! Cannot insert %d.\n", item);
        return;
    }

    if (c_front == -1) {
        c_front = 0;
        c_rear = 0;
    } else if (c_rear == MAX - 1) {
        c_rear = 0;
    } else {
        c_rear++;
    }

    c_queue[c_rear] = item;
    printf(" %d inserted at index %d.\n", item, c_rear);
}

void deleteCircular() {
    if (c_front == -1) {
        printf("\n Circular Queue Underflow! Queue is empty.\n");
        return;
    }

    printf(" %d deleted from index %d.\n", c_queue[c_front], c_front);

    if (c_front == c_rear) {
        c_front = -1;
        c_rear = -1;
    } else if (c_front == MAX - 1) {
        c_front = 0;
    } else {
        c_front++;
    }
}

void displayCircular() {
    if (c_front == -1) {
        printf("\n Circular Queue is empty.\n");
        return;
    }

    printf("\n Circular Queue elements: ");
    int i = c_front;

    while (1) {
        printf("%d", c_queue[i]);
        if (i == c_rear) break;

        if (i == MAX - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    printf("\n Front Index: %d | Rear Index: %d\n", c_front, c_rear);
}

void circularQueueMenu() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue ---");
        printf("\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit");
        printf("\n Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(" Enter value to insert: ");
                scanf("%d", &value);
                insertCircular(value);
                break;
            case 2:
                deleteCircular();
                break;
            case 3:
                displayCircular();
                break;
            case 4:
                return;
            default:
                printf(" Invalid choice!\n");
        }
    }
}

int main() {
    circularQueueMenu();
    return 0;
}
