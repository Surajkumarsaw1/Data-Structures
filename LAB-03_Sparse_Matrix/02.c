// WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>
#include <stdlib.h>

void traverse_sparse_matrix(int sm[][3])
{

    int n = sm[0][2];
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%6d %6d %6d\n", sm[i][0], sm[i][1], sm[i][2]);
        if (i == 0)
        {
            int length = 7 * 3; // Length of the line

            // Loop to print hyphens
            for (int i = 0; i < length; i++)
            {
                printf("-");
            }

            printf("\n"); // Move to the next line after drawing the line
        }
    }
    printf("\n");
    // sparse_to_normal(sm);
}

typedef int (*IntArray3Ptr)[3];

IntArray3Ptr input_sm()
{
    int row, col, n, r_value, c_value, value;
    printf("Enter sparse matrix in 3-tuple format\n");
    printf("Enter number of row, col and non-zero element: ");
    scanf("%d%d%d", &row, &col, &n);

    IntArray3Ptr sparse_matrix = malloc((n + 1) * sizeof(int[3]));

    if (sparse_matrix == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    sparse_matrix[0][0] = row;
    sparse_matrix[0][1] = col;
    sparse_matrix[0][2] = n;

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the row, col, value: ");
        scanf("%d%d%d", &r_value, &c_value, &value);
        sparse_matrix[i][0] = r_value;
        sparse_matrix[i][1] = c_value;
        sparse_matrix[i][2] = value;
    }

    traverse_sparse_matrix(sparse_matrix);

    return sparse_matrix;
}

IntArray3Ptr add_sparse(int sm1[][3], int sm2[][3])
{
    int row1 = sm1[0][0], col1 = sm1[0][1], n1 = sm1[0][2];
    int row2 = sm2[0][0], col2 = sm2[0][1], n2 = sm2[0][2];

    if ((row1 != row2) || (col1 != col2))
    {
        printf("Matrixes are not of the same order. Addition not possible.\n");
        return NULL;
    }

    // Create a new sparse matrix to store the sum
    int n_sum = n1 + n2;
    IntArray3Ptr sm_sum = malloc((n_sum + 1) * sizeof(int[3]));
    // int sm_sum[n_sum + 1][3];

    if (sm_sum == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    sm_sum[0][0] = row1;
    sm_sum[0][1] = col1;
    sm_sum[0][2] = 0; // Initialize the count of non-zero elements in the result

    int k1 = 1;
    int k2 = 1;        // Index for iterating through sm1 and sm2
    int sum_index = 1; // Index for iterating through sm_sum

    for (int r = 0; r < row1; r++)
    {
        for (int c = 0; c < col1; c++)
        {
            // printf("r = %d, c = %d\n", r, c);
            if ((sm1[k1][0] == r && sm1[k1][1] == c) && (sm2[k2][0] == r && sm2[k2][1] == c))
            {
                // Both matrices have non-zero values at this position
                // printf("\tBoth have value at the position\n");
                sm_sum[sum_index][0] = r;
                sm_sum[sum_index][1] = c;
                sm_sum[sum_index][2] = sm1[k1][2] + sm2[k2][2];
                k1++;
                k2++;
            }
            else if ((sm1[k1][0] == r && sm1[k1][1] == c))
            {
                // Only sm1 has a non-zero value at this position
                // printf("\tsm1 have value at the position\n");
                sm_sum[sum_index][0] = r;
                sm_sum[sum_index][1] = c;
                sm_sum[sum_index][2] = sm1[k1][2];
                k1++;
            }
            else if ((sm2[k2][0] == r && sm2[k2][1] == c))
            {
                // Only sm2 has a non-zero value at this position
                // printf("\tsm2 have value at the position\n");
                sm_sum[sum_index][0] = r;
                sm_sum[sum_index][1] = c;
                sm_sum[sum_index][2] = sm2[k2][2];
                k2++;
            }
            // else
            // {
            //     // Both matrices are zero at this position
            //     sm_sum[sum_index][0] = r;
            //     sm_sum[sum_index][1] = c;
            //     sm_sum[sum_index][2] = 0;
            // }

            if (sm_sum[sum_index][2] != 0)
            {
                sum_index++;
                sm_sum[0][2] = sum_index - 1; // Increment the count of non-zero elements
            }

            // sum_index++;
        }
    }

    return sm_sum;
}

int main()
{
    IntArray3Ptr sm1 = input_sm(), sm2 = input_sm();

    IntArray3Ptr sm_sum = add_sparse(sm1, sm2);

    if (sm_sum != NULL)
    {
        printf("\nSum of sparse matrices:\n");
        traverse_sparse_matrix(sm_sum);
        free(sm1);
        free(sm2);
        free(sm_sum); // Free the memory allocated for the sum matrix
    }

    return 0;
}
