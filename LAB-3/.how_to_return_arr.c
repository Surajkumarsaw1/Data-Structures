#include <stdio.h>
#include <stdlib.h>

// Function to take input for an array and return it
int* inputArray(int *size) {
    int *arr;
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory dynamically for the array
    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    *size = n; // Update the size of the array
    return arr;
}

int main() {
    int *myArray, *myArray2;
    int size;

    // Call the function to input the array
    myArray = inputArray(&size);
    myArray2 = inputArray(&size);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }

    // Free the dynamically allocated memory
    free(myArray);

    return 0;
}
