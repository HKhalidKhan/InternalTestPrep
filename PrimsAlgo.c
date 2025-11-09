#include <stdio.h>

#define INF 9999
#define MAX 10

int main() {
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int n; // number of vertices
    int edges = 0;
    int i, j;
    int min, u, v;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // No direct edge
        }
    }

    visited[0] = 1; // Start from vertex 0

    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INF;
        u = v = -1;

        // Find the minimum cost edge between visited and unvisited vertices
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d -> %d  cost = %d\n", u, v, cost[u][v]);
            totalCost += cost[u][v];
            visited[v] = 1;
            edges++;
        }
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", totalCost);
    return 0;
}
