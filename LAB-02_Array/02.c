//  WAP that takes an array as input and removes any duplicate elements, keeping only the first occurrence of each element.

#include <stdio.h>
#include <stdlib.h>

void delete_element(int *arr, int index, int *n) {
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void delete_all_duplicate(int **arr, int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n;) {
            if ((*arr)[i] == (*arr)[j]) {
                delete_element(*arr, j, n);
            } else {
                j++;
            }
        }
    }
    *arr = (int *)realloc(*arr, (*n) * sizeof(int));
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    delete_all_duplicate(&arr, &n);

    printf("Array after deleting duplicates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
