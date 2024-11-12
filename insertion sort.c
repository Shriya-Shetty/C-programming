#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10; // Size of the array
    int arr[n]; // Declare an array of size n

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read each element from the user
    }

    // Insertion sort algorithm
    for (int i = 1; i < n; i++) {
        int temp = arr[i]; // Store the current element
        int j = i - 1; // Start comparing with the previous element

        // Move elements of arr[0..i-1], that are greater than temp, to one position ahead of their current position
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j]; // Shift element to the right
            j--; // Move to the previous element
        }
        arr[j + 1] = temp; // Insert the temp at the correct position
    }

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element
    }
    printf("\n"); // New line for better formatting

    return 0; // End of the program
}
