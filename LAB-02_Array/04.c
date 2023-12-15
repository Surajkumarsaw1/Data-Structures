// WAP to create a nXn matrix and perform the following:
//         e. Find the number of non zero elements
//         f. Sum and average of elements row wise
//         g. Sum and average of elements column wise

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int non_zero(int **matrix, int row, int col)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        // printf("\n%p\t", matrix[i]);
        for (int j = 0; j < col; j++)
        {
            // printf("%d\t", matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

void row_sum_and_average(int **matrix, int row, int col)
{
    float sum[row], average[row];
    memset(sum, 0, sizeof(sum)); // This will reinitialize all to ZERO
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum[i] += matrix[i][j];
        }
        average[i] = sum[i] / col;
        printf("Row %d : Sum : %f, Average : %f\n", i, sum[i], average[i]);
    }
}

void col_sum_and_average(int **matrix, int row, int col)
{
    float sum[row], average[row];
    memset(sum, 0, sizeof(sum)); // This will reinitialize all to ZERO
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            sum[i] += matrix[j][i];
        }
        average[i] = sum[i] / col;
        printf("Col %d : Sum : %f, Average : %f\n", i, sum[i], average[i]);
    }
}

int main()
{
    int n;

    printf("Enter value of n for nXn martix : ");
    scanf("%d", &n);
    // int *row = (int *)malloc(n * sizeof(int));
    int **matrix = (int **)malloc(n * sizeof(int *));

    // printf("\nAddress of matrix : %p\n\n", matrix);

    printf("Enter %d elements of matix : \n", n * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        // printf("%p\t Row %d : ", matrix[i], i);
        printf("Row %d : ", i);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
            // printf("%d\t", matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        // printf("%p\t", matrix[i]);
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        
    }

    printf("\nNumber of non-zero elements : %d\n", non_zero(matrix, n, n));
    printf("\nSum and Average of Rows : \n");
    row_sum_and_average(matrix, n, n);
    printf("\nSum and Average of Columns : \n");
    col_sum_and_average(matrix, n, n);

    free(matrix);

    return 0;
}