// In addition to Q1, display BFS traversal sequence of the undirected graph.

#include <stdio.h>
#include <stdlib.h>

void DFS(int **adjacencyMatrix, int *visited, int start, int n);
void BFS(int **adjacencyMatrix, int *visited, int start, int n);
void printAdjacencyMatrix(int **adjacencyMatrix, int n);
void printVertexDegree(int **adjacencyMatrix, int n);

int isValidVertex(int vertex, int n)    
{
    return (vertex >= 0 && vertex < n);
}

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

    int option;

    do
    {
        printf("\nMenu:\n");
        printf("1. Print Adjacency Matrix\n");
        printf("2. Print Degree of Each Vertex\n");
        printf("3. Perform DFS\n");
        printf("4. Perform BFS\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printAdjacencyMatrix(adjacencyMatrix, n);
            break;
        case 2:
            printVertexDegree(adjacencyMatrix, n);
            break;
        case 3:
        {
            int *visitedDFS = (int *)calloc(n, sizeof(int));
            int startDFS;
            do
            {
                printf("Enter start vertex for DFS (0-%d): ", n - 1);
                scanf("%d", &startDFS);

                if (!isValidVertex(startDFS, n))
                {
                    printf("Invalid vertex. Please enter a valid vertex.\n");
                }

            } while (!isValidVertex(startDFS, n));

            printf("DFS Start -> ");
            DFS(adjacencyMatrix, visitedDFS, startDFS, n);
            printf(" DFS End\n");
            free(visitedDFS);
        }
        break;
        case 4:
        {
            int *visitedBFS = (int *)calloc(n, sizeof(int));
            int startBFS;
            do
            {
                printf("Enter start vertex for BFS (0-%d): ", n - 1);
                scanf("%d", &startBFS);

                if (!isValidVertex(startBFS, n))
                {
                    printf("Invalid vertex. Please enter a valid vertex.\n");
                }

            } while (!isValidVertex(startBFS, n));

            printf("BFS Start -> ");
            BFS(adjacencyMatrix, visitedBFS, startBFS, n);
            printf(" BFS End\n");
            free(visitedBFS);
        }
        break;
        case 5:
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (option != 5);

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

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

void BFS(int **adjacencyMatrix, int *visited, int start, int n)
{
    int queue[n];
    int front = -1, rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear)
    {
        start = queue[++front];
        printf("%d -> ", start);

        for (int i = 0; i < n; i++)
        {
            if (adjacencyMatrix[start][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void printAdjacencyMatrix(int **adjacencyMatrix, int n)
{
    printf("\nAdjacency Matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void printVertexDegree(int **adjacencyMatrix, int n)
{
    printf("\nDegree of each vertex.\n");
    printf("Vertex\tDegree\n");
    for (int i = 0; i < n; i++)
    {
        int degree = 0;
        for (int j = 0; j < n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                degree++;
            }
        }
        printf("%d\t%d\n", i, degree);
    }
}
