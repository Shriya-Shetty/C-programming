#include <stdio.h>
#include <stdlib.h>

// Function to insert an element into the array using linear probing
void insert(int arr[], int n, int *collision_count) {
    int k; // Variable to hold the element to be inserted
    printf("Enter element to insert: ");
    scanf("%d", &k); // Read the element from the user

    int i = 0; // Variable to handle probing
    int num = (k % n); // Calculate the initial index using the hash function
    // Check if the position is empty
    if (arr[num] == -1) {
        arr[num] = k; // Insert the element if the position is empty
    } else {
        // If the position is occupied, use linear probing to find the next available spot
        while (arr[num] != -1) {
            i++; // Increment the probe count
            num = (k % n + i) % n; // Calculate the next index
            (*collision_count)++; // Increment the collision counter
        }
        arr[num] = k; // Insert the element at the found position
    }
}

// Function to search for an element in the array using linear probing
void search(int arr[], int n) {
    int m; // Variable to hold the element to search for
    printf("Enter the element you want to search: ");
    scanf("%d", &m); // Read the element from the user

    int num = (m % n); // Calculate the initial index using the hash function
    // Check if the element is at the calculated index
    if (arr[num] == m) {
        printf("Element found at position: %d\n", (num + 1)); // Print the position
    } else {
        int i = 1; // Variable to handle probing for search
        // Use linear probing to find the element
        while (arr[num] != -1) {
            if (arr[num] == m) { // Check if the current position has the element
                printf("Element found at position: %d\n", (num + 1)); // Print the position
                return; // Exit the function
            }
            i++; // Increment the probe count
            num = (m % n + i) % n; // Calculate the next index
        }
        printf("Element not found in the array.\n"); // If not found
    }
}

// Function to display the contents of the array
void display(int arr[], int n) {
    printf("Array after inserting elements:\n");
    for (int k = 0; k < n; k++) {
        printf("arr[%d] = %d\n", k, arr[k]); // Print each element in the array
    }
}

// Main function to drive the program
int main() {
    int n; // Variable for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); // Read the size of the array from the user
    int arr[n]; // Declare the array of the specified size

    // Initialize the array with -1 (indicating empty slots)
    for (int k = 0; k < n; k++) {
        arr[k] = -1; // Mark all positions as empty
    }
    int collision_count = 0; // Counter for collisions during insertion
    int choice; // Variable to hold the user's menu choice

    do {
        // Display the menu options to the user
        printf("\nMenu:\n");
        printf("1. Linear Probing Insertion\n");
        printf("2. Linear Probing Search\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        // Switch statement to execute the corresponding action based on the choice
        switch (choice) {
            case 1:
                insert(arr, n, &collision_count); // Call the insertion function
                break;
            case 2:
                search(arr, n); // Call the search function
                break;
            case 3:
                display(arr, n); // Call the display function
                printf("Number of collisions that occurred = %d\n", collision_count); // Show collision count
                break;
            case 4:
                printf("Exiting...\n"); // Exit message
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid choices
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0; // End of the program
}
