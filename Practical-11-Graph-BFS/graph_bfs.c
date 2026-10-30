#include <stdio.h>

int graph[20][20], visited[20], queue[20];
int n, front = 0, rear = -1;

void BFS(int start)
{
    int i, vertex;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid number of vertices!");
        return 0;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex!");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}