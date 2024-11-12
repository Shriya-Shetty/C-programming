#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Define the maximum size of the deque

// Declare the deque structure
int deque[MAX];
int front = -1; // Initialize front to -1, indicating an empty deque
int rear = -1;  // Initialize rear to -1, indicating an empty deque

// Function to check if the deque is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to add an element at the front of the deque
void insertFront(int x) {
    if (isFull()) {
        printf("Deque is full\n");
    } else {
        if (front == -1) { // Deque is empty
            front = rear = 0; // Set both front and rear to 0
        } else {
            front = (front - 1 + MAX) % MAX; // Circular decrement for front
        }
        deque[front] = x; // Insert the element at the front
    }
}

// Function to add an element at the rear of the deque
void insertRear(int x) {
    if (isFull()) {
        printf("Deque is full\n");
    } else {
        if (front == -1) { // Deque is empty
            front = rear = 0; // Set both front and rear to 0
        } else {
            rear = (rear + 1) % MAX; // Circular increment for rear
        }
        deque[rear] = x; // Insert the element at the rear
    }
}

// Function to remove an element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty (underflow)\n");
    } else {
        printf("Deleted element from front: %d\n", deque[front]);
        if (front == rear) { // If the deque becomes empty
            front = rear = -1; // Reset front and rear
        } else {
            front = (front + 1) % MAX; // Circular increment for front
        }
    }
}

// Function to remove an element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty (underflow)\n");
    } else {
        printf("Deleted element from rear: %d\n", deque[rear]);
        if (front == rear) { // If the deque becomes empty
            front = rear = -1; // Reset front and rear
        } else {
            rear = (rear - 1 + MAX) % MAX; // Circular decrement for rear
        }
    }
}

// Function to display the elements in the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");
    while (1) {
        printf("%d ", deque[i]); // Print the current element
        if (i == rear) break; // Stop if we've reached the rear
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}

// Main function to demonstrate deque operations
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(30);
    display(); // Display current elements in the deque

    deleteFront();
    display(); // Display after deleting from front

    insertFront(40);
    insertRear(50);
    display(); // Display current elements in the deque

    deleteRear();
    display(); // Display after deleting from rear

    return 0; // End of the program
}
