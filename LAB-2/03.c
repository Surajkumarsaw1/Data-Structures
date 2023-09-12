#include <stdio.h>
#include <stdlib.h>

void traverse(int arr[], int n)
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int **arr, int *n, int element, int position)
{

    (*n)++;
    *arr = (int *)realloc(*arr, (*n) * sizeof(int));

    if (*arr == NULL)
    {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    for (int i = *n - 1; i > position; i--)
    {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[position] = element;
    return 1;
}

int delete_element(int **arr, int *n, int index)
{
    if (*n <= 0)
    {
        printf("Array is empty. Deletion failed.\n");
        return 0;
    }

    if (index < 0 || index >= *n)
    {
        printf("Invalid position for deletion. Deletion failed.\n");
        return 0;
    }
    for (int i = index; i < *n - 1; i++)
    {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*n)--;
    *arr = (int *)realloc(*arr, (*n) * sizeof(int));

    return 1;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeArrays(int **arr1, int *n1, int *arr2, int *n2)
{
    // Sort both arrays before merging
    bubbleSort(*arr1, *n1);
    bubbleSort(arr2, *n2);

    // Calculate the new size of arr1 after merging
    int newSize = *n1 + *n2;

    // Reallocate memory for arr1 to accommodate the merged elements
    *arr1 = (int *)realloc(*arr1, newSize * sizeof(int));

    if (*arr1 == NULL)
    {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    // Merge the two sorted arrays
    int i = *n1 - 1;
    int j = *n2 - 1;
    int k = newSize - 1;

    while (i >= 0 && j >= 0)
    {
        if ((*arr1)[i] >= arr2[j])
        {
            (*arr1)[k] = (*arr1)[i];
            i--;
        }
        else
        {
            (*arr1)[k] = arr2[j];
            j--;
        }
        k--;
        // traverse(*arr1, newSize);
    }

    while (j >= 0)
    {
        (*arr1)[k] = arr2[j];
        j--;
        k--;
    }

    *n1 = newSize;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int choice;
    int element, position;
    int n2;
    int *arr2;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Merge\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse(arr, n);
            break;
        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            if (insert(&arr, &n, element, position))
            {
                printf("Element inserted successfully.\n");
                traverse(arr,n);
            }
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            if (delete_element(&arr, &n, position))
            {
                printf("Element deleted successfully.\n");
                traverse(arr,n);
            }
            break;
        case 4:
            printf("Enter the value of n2: ");
            scanf("%d", &n2);

            arr2 = (int *)malloc(n2 * sizeof(int));
            if (arr2 == NULL)
            {
                printf("Memory allocation failed. Exiting...\n");
                return 1;
            }

            printf("Enter %d elements for the second array: ", n2);
            for (int i = 0; i < n2; i++)
            {
                scanf("%d", &arr2[i]);
            }

            mergeArrays(&arr, &n, arr2, &n2);
            free(arr2);
            printf("Arrays merged successfully.\n");
            traverse(arr,n);
            break;
        case 5:
            free(arr);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
