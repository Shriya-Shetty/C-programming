#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;  // Use the passed value for data
    newnode->next = NULL;

    if (rear == NULL) { // Queue is empty
        front = rear = newnode;
        rear->next = front; // Circular link
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front; // Maintain circular link
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;

    if (front == rear) { // Only one node
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Maintain circular link
    }

    free(temp); // Free the dequeued node
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue elements: ");
    display();

    dequeue();
    printf("After dequeue: ");
    display();

    return 0;
}
