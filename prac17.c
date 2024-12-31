#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

int graph[MAX][MAX], parent[MAX], cost[MAX], visited[MAX], vertices, edges, choice;

void choose_operation()
{
    printf("\nMenu:\n");
    printf("1. Dijkstra's Shortest Path\n");
    printf("2. Kruskal's Minimum Spanning Tree\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
}

void dijkstra(int start)
{
    int min, u, v;
    
    for (int i = 0; i < vertices; i++)
    {
        cost[i] = INF;
        visited[i] = 0;
    }
    cost[start] = 0;

    for (int count = 0; count < vertices - 1; count++)
    {
        min = INF;
        u = -1;

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i] && cost[i] < min)
            {
                min = cost[i];
                u = i;
            }
        }

        visited[u] = 1;


        for (v = 0; v < vertices; v++)
        {
            if (!visited[v] && graph[u][v] != INF && cost[u] + graph[u][v] < cost[v])
            {
                cost[v] = cost[u] + graph[u][v];
            }
        }
    }

    printf("Shortest path from node %d:\n", start);
    for (int i = 0; i < vertices; i++)
    {
        if (cost[i] == INF)
        {
            printf("Node %d is unreachable.\n", i);
        }
        else
        {
            printf("Distance from node %d to node %d: %d\n", start, i, cost[i]);
        }
    }
}

int find_parent(int i)
{
    if (parent[i] == i)
        return i;
    else
        return find_parent(parent[i]);
}

void union_sets(int root1, int root2)
{
    if (root1 != root2)
    {
        parent[root2] = root1;
    }
}

void kruskal()
{
    int min_cost = 0, edge_count = 0;
    int u, v;
    int i = 0;

    while (edge_count < vertices - 1)
    {
        int min = INF, a = -1, b = -1;

        // Find the edge with the smallest weight that doesn't form a cycle
        for (int i = 0; i < edges; i++)
        {
            u = find_parent(graph[i][0]);
            v = find_parent(graph[i][1]);

            if (u != v && graph[i][2] < min)
            {
                min = graph[i][2];
                a = u;
                b = v;
            }
        }

        if (a != -1 && b != -1)
        {
            min_cost += min;
            edge_count++;
            union_sets(a, b);
            printf("Edge included in MST: %d - %d with weight %d\n", a, b, min);
        }
    }

    printf("Minimum cost of the spanning tree: %d\n", min_cost);
}

void traversal()
{
    if (choice == 1)
    {
        int start;
        printf("Enter the starting node for Dijkstra's: ");
        scanf("%d", &start);
        dijkstra(start);
    }
    else if (choice == 2)
    {
        printf("Enter the number of edges: ");
        scanf("%d", &edges);
        printf("Enter the edges (u v w) where u and v are the nodes and w is the weight:\n");

        for (int i = 0; i < edges; i++)
        {
            int u, v, w;
            printf("Enter edge %d (u v w): ", i + 1);
            scanf("%d %d %d", &u, &v, &w);
            graph[i][0] = u;
            graph[i][1] = v;
            graph[i][2] = w;

            parent[u] = u;
            parent[v] = v;
        }

        printf("\nKruskal's Algorithm:\n");
        kruskal();
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
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }


    while (1)
    {
        choose_operation();
        traversal();
    }

    return 0;
}
