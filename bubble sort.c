#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // Variable to hold the size of the array

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); // Read the size from the user

    int arr[n]; // Declare an array of size n

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read each element from the user
    }

    // Bubble Sort algorithm
    for (int i = 0; i < n - 1; i++) { // Loop for each element
        int swapped = 0; // Flag to check if a swap occurred
        for (int j = 0; j < n - i - 1; j++) { // Inner loop for comparisons
            if (arr[j] > arr[j + 1]) { // If the current element is greater than the next
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag indicating a swap occurred
            }
        }
        // If no swaps were made, the array is already sorted
        if (swapped == 0) {
            break; // Exit the loop early
        }
    }

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element
    }
    printf("\n"); // New line for better formatting

    return 0; // End of the program
}
