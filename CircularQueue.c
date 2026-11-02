#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int element) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1 )) {
        printf("Queue Overflow\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = element;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = element;
    } else {
        rear++;
        queue[rear] = element;
    }
    printf("Inserted %d\n", element);
}

void delete() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    int data = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Deleted %d\n", data);
}

void display() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
