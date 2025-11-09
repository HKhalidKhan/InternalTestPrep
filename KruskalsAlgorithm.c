#include <stdio.h>

#define MAX 30

int parent[MAX];

// Function to find the parent (root) of a vertex
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to join two sets
int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int cost[MAX][MAX];
    int n;
    int edges = 1;
    int min, a, b, u, v;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999; // Treat 0 as infinity (no edge)
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n) {
        min = 9999;

        // Find the smallest edge
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        // If they are not forming a cycle
        if (unionSet(u, v)) {
            printf("%d -> %d  cost = %d\n", a, b, min);
            totalCost += min;
            edges++;
        }

        // Remove the edge from consideration
        cost[a][b] = cost[b][a] = 9999;
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", totalCost);
    return 0;
}
