#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, term, count = 0;

    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d numbers :\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%d", arr + i);
    }

    printf("Enter the search term: ");
    scanf("%d", &term);

    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) == term)
        {
            printf("Found at index : %d\n", i);
            count++;
            break;
        }
    }
    if (count == 0)
    {
        printf("No match found.\n");
    }

    free(arr);
    return 0;
}