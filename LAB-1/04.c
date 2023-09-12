#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, max, min;

    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%d", arr + i);
    }

    max = *arr;
    min = *arr;

    for (i = 0; i < n; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
        else if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }
    printf("Smallest : %d, Largest : %d\n", min, max);
    free(arr);
    return 0;
}