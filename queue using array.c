#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) { // Fixed comparison
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1; // Reset the queue
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("No queue made\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]); // Print with space
    }
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(2);
    enqueue(1);
    peek();
    display();
    dequeue();
    display();

    return 0;
}
