#include <stdio.h>
#define MAX 20
#define INF 9999

int main() {
    int n, i, j, k;
    int cost[MAX][MAX], dist[MAX], visited[MAX], min, next;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // No direct edge
        }
    }

    int source;
    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    // Initialization
    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }
    dist[source] = 0;
    visited[source] = 1;

    // Dijkstra's main loop
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && (dist[next] + cost[next][j] < dist[j])) {
                dist[j] = dist[next] + cost[next][j];
            }
        }
    }

    // Print the results
    printf("\nShortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("To vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}
