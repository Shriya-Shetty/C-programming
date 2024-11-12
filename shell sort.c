#include <stdio.h>

void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            // Save the current element to be compared
            int temp = arr[i];
            int j;
            // Shift earlier gap-sorted elements up until the correct location for temp is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // Shift element
            }
            arr[j] = temp; // Put temp in the correct location
        }
    }
}

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

    // Call the shell sort function
    shellSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element
    }
    printf("\n"); // New line for better formatting

    return 0; // End of the program
}
