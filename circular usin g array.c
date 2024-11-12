#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty (underflow)\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Should display the queue elements

    dequeue();
    display(); // Should display the updated queue

    enqueue(40);
    enqueue(50);
    enqueue(60); // This should show "Queue is full"
    display();

    dequeue();
    dequeue();
    dequeue();
    display(); // Should show the queue after dequeue operations

    return 0;
}
