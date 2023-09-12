#include <stdio.h>
#include <stdlib.h>

void pointerswap(int *a, int*b){
    // printf("a = %d, b = %d",*a,*b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;

    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d numbers : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }

    for (int i = 0; i < n / 2; i++)
    {
        pointerswap( (arr+i), (arr+((n-1)-i)) );
    }

    for (int i = 0; i < n; i++){
        printf("%d ",*(arr+i));
    }

    return 0;
}