#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* front = NULL; // Pointer to the front of the queue
struct node* rear = NULL;  // Pointer to the rear of the queue

// Function to enqueue an element
void enqueue(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;

    if (rear == NULL) { // If the queue is empty
        front = rear = newNode;
    } else {
        rear->link = newNode; // Link new node to the end
        rear = newNode;       // Update rear to the new node
    }
}

// Function to dequeue an element
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front; // Node to be dequeued
    printf("Dequeued: %d\n", front->data);
    front = front->link; // Move front to the next node

    if (front == NULL) { // If the queue is now empty
        rear = NULL; // Update rear as well
    }

    free(temp); // Free the dequeued node
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* ptr = front; // Start from the front
    printf("Queue elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

// Function to peek at the front element
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

int main() {
    // Example usage
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    peek();
    dequeue();
    display();

    return 0;
}
