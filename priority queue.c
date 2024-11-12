#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum number of elements in the priority queue

// Structure to represent an element in the priority queue
struct PriorityQueue {
    int data;
    int priority;
};

// Declare the priority queue and its size
struct PriorityQueue pq[MAX];
int size = 0; // Current size of the priority queue

// Function to check if the priority queue is full
int isFull() {
    return size == MAX;
}

// Function to check if the priority queue is empty
int isEmpty() {
    return size == 0;
}

// Function to insert an element into the priority queue
void insert(int data, int priority) {
    if (isFull()) {
        printf("Priority Queue is full\n");
        return;
    }

    // Create a new element
    struct PriorityQueue newElement;
    newElement.data = data;
    newElement.priority = priority;

    // Find the correct position for the new element
    int i;
    for (i = size - 1; (i >= 0 && pq[i].priority < priority); i--) {
        pq[i + 1] = pq[i]; // Shift elements down
    }

    pq[i + 1] = newElement; // Insert the new element
    size++; // Increase the size of the queue
}

// Function to remove and return the element with the highest priority
struct PriorityQueue delete() {
    if (isEmpty()) {
        printf("Priority Queue is empty\n");
        exit(EXIT_FAILURE); // Exit if the queue is empty
    }
    return pq[--size]; // Return the highest priority element and decrease size
}

// Function to display the priority queue
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements (data:priority): ");
    for (int i = 0; i < size; i++) {
        printf("(%d:%d) ", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

// Main function to demonstrate priority queue operations
int main() {
    insert(10, 2); // Insert element with data 10 and priority 2
    insert(20, 1); // Insert element with data 20 and priority 1
    insert(30, 3); // Insert element with data 30 and priority 3
    display(); // Display the current elements in the priority queue

    struct PriorityQueue element = delete(); // Remove the element with the highest priority
    printf("Deleted element with data: %d and priority: %d\n", element.data, element.priority);
    display(); // Display after deletion

    return 0; // End of the program
}
ww
