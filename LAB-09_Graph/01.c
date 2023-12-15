// WAP to create an un-directed graph using Adjacency Matrix Method and display the degree of each vertex. 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, degree;
    char adj;

    printf("Enter a number of vertices: ");
    scanf("%d", &n);

    int **adjacencyMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adjacencyMatrix[i] = (int *)malloc(n * sizeof(int));
        // Initialize the matrix
        for (int j = 0; j < n; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                continue;
            }
            else
            {
                printf("Vertices %d & %d are Adjacent? (Y/N): ", i, j);
                scanf(" %c", &adj);
                if (adj == 'y' || adj == 'Y')
                {
                    adjacencyMatrix[i][j] = 1;
                    adjacencyMatrix[j][i] = 1;
                }
            }
        }
    }

    printf("\nAdjacency Matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nDegree of each vertex.\n");
    printf("Vertex\tDegree\n");
    for (int i = 0; i < n; i++)
    {
        degree = 0;
        for (int j = 0; j < n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                degree++;
            }
        }
        printf("%d\t%d\n", i, degree);
    }

    return 0;
}
