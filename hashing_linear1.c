#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Define a size for the hash table

int main() {
    int array[] = {29, 18, 43, 10, 36, 25, 46}; // Input array
    int arraySize = sizeof(array) / sizeof(array[0]); // Size of the input array
    int newTable[TABLE_SIZE]; // Hash table
    // Initialize the newTable to -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        newTable[i] = -1;
    }

    for (int i = 0; i < arraySize; i++) {
        int insert_position = array[i] % TABLE_SIZE; // Calculate the initial position
        // Linear probing to find the next available slot
        while (newTable[insert_position] != -1) {
            insert_position = (insert_position + 1) % TABLE_SIZE; // Move to the next position
        }
        newTable[insert_position] = array[i]; // Insert the value
    }

    // Print the hash table
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (newTable[i] != -1) {
            printf("%d ", newTable[i]);
        } else {
            printf("NULL ");
        }
    }
    printf("\n");

    return 0;
}
