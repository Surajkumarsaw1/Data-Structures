//  In addition to Q1, display DFS traversal sequence of the undirected graph.

#include <stdio.h>
#include <stdlib.h>

void DFS(int **adjacencyMatrix, int *visited, int start, int n);

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

    printf("Depth First Search : \n");

    int *visited = (int *)calloc(n, sizeof(int));
    int start;

    printf("Enter start vertex (0-%d): ", n - 1);
    scanf("%d", &start);

    printf("Start -> "); 
    DFS(adjacencyMatrix, visited, start, n);
    printf(" End");

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);
    free(visited);

    return 0;
}

void DFS(int **adjacencyMatrix, int *visited, int start, int n)
{
    if (start < n && start >= 0)
    {
        visited[start] = 1;
        printf("%d -> ", start);

        for (int i = 0; i < n; i++)
        {
            if (adjacencyMatrix[start][i] == 1 && !visited[i])
            {
                DFS(adjacencyMatrix, visited, i, n);
            }
        }
    }
    else
    {
        printf("Not a valid vertex.");
    }
}
