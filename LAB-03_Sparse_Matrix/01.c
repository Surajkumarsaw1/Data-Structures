// WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>
#include <stdlib.h>

void sparse_to_normal(int sm[][3])
{
    int row = sm[0][0], col = sm[0][1], n = sm[0][2], temp;
    printf("\n\v");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if ((i == sm[k][0]) && (j == sm[k][1]))
                {
                    // printf("[%d][%d]-[%d]:%d",i,j,k);
                    temp = sm[k][2];
                    break;
                }
                else
                {
                    temp = 0;
                }
            }
            printf("%d\t", temp);
        }
        printf("\n");
    }
}

void traverse_sparse_matrix(int sm[][3])
{

    int n = sm[0][2];
    for (int i = 0; i <= n; i++)
    {
        printf("%6d %6d %6d\n", sm[i][0], sm[i][1], sm[i][2]);
        if (i == 0)
        {
            int length = 7*3; // Length of the line

            for (int i = 0; i < length; i++)
            {
                printf("-");
            }

            printf("\n"); 
        }
    }
    // sparse_to_normal(sm);
}

void transpose_sparse_matrix(int sm[][3])
{

    int n = sm[0][2], temp, row, col, count = 1;
    int tm[n+1][3];

    row = sm[0][0];
    col = sm[0][1];

    tm[0][0] = sm[0][1];
    tm[0][1] = sm[0][0];
    tm[0][2] = sm[0][2];

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                // printf("i:col =  %d, j:row = %d, k:%d, [0] = %d, [1] = %d, [3]:%d \n",i,j,k,sm[k][0],sm[k][1],sm[k][2]);
                if ((sm[k][1] == i) && (sm[k][0] == j))
                {
                    // printf("\ti:col =  %d, j:row = %d, k:%d, [0] = %d, [1] = %d, [3]:%d \n", i, j, k, sm[k][0], sm[k][1], sm[k][2]);
                    tm[count][0] = sm[k][1];
                    tm[count][1] = sm[k][0];
                    tm[count][2] = sm[k][2];
                    count++;
                }
            }
        }
    }
    printf("\nTranspose : \n");
    traverse_sparse_matrix(tm);
    // sparse_to_normal(tm);
}

int main()
{
    int row, col, n, r_value, c_value, value, temp;
    printf("Enter row, col, number of non-zero element : ");
    scanf("%d%d%d", &row, &col, &n);

    int sm[n + 1][3];

    sm[0][0] = row;
    sm[0][1] = col;
    sm[0][2] = n;

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the row, col, value : ");
        scanf("%d%d%d", &r_value, &c_value, &value);
        sm[i][0] = r_value;
        sm[i][1] = c_value;
        sm[i][2] = value;
    }

    traverse_sparse_matrix(sm);

    transpose_sparse_matrix(sm);

    return 0;
}