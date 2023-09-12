#include <stdio.h>
#include <stdlib.h>

// Define a type for a pointer to an array of 3 integers
typedef int (*IntArray3Ptr)[3];

// Function to create and return a 2D matrix
IntArray3Ptr createMatrix(int rows)
{
    // Dynamically allocate memory for the 2D matrix
    int(*matrix)[3] = malloc(rows * sizeof(int[3]));
    printf("matrix : %p\n", matrix);
    if (matrix == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the matrix (optional)
    for (int i = 0; i < rows; i++)
    {
        printf("\tmatrix[%d] : %p\n", i, matrix[i]);

        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = 0; // You can initialize with any value you want
        }
    }

    return matrix;
}

int main()
{
    printf("Size of int : %ld\n",sizeof(int));
    int rows = 4; // Change the number of rows as needed

    // Create a 2D matrix with 3 columns
    IntArray3Ptr myMatrix = createMatrix(rows);

    // Access and modify elements of the 2D matrix
    myMatrix[0][0] = 1;
    myMatrix[1][1] = 2;

    // Print the 2D matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", myMatrix[i][j]);
        }
        printf("\n");
    }

    // Don't forget to free the allocated memory when done with the matrix
    free(myMatrix);

    return 0;
}
