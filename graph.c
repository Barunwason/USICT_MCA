#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int graph[10][10]; 
int visited[10]; 
int vertices;
int choice; 

void choose_operation()
{
    printf("\nMenu:\n");
    printf("1. Depth-First Search (DFS)\n");
    printf("2. Breadth-First Search (BFS)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
}

void dfs(int node)
{
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < vertices+1; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

void bfs(int start)
{
    int queue[10], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void traversal()
{
    for (int i = 0; i < vertices+1; i++)
    {
        visited[i] = 0;
    }

    if (choice == 1)
    {
        int start_node;
        printf("\nEnter the starting node for DFS: ");
        scanf("%d", &start_node);
        printf("Depth-First Search (DFS) traversal starting from node %d:\n", start_node);
        dfs(start_node);
    }
    else if (choice == 2)
    {
        int start_node;
        printf("\nEnter the starting node for BFS: ");
        scanf("%d", &start_node);
        printf("Breadth-First Search (BFS) traversal starting from node %d:\n", start_node);
        bfs(start_node);
    }
}

int main()
{
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);


    for (int i = 0; i < edges; i++)
    {
        int u, v;
        printf("Enter edge %d (format: u v): ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    while (1)
    {
        choose_operation();
        traversal();
    }

    return 0;
}
