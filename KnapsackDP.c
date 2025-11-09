#include <stdio.h>

// Function to return the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build the DP table bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Return the maximum value that can be put in the knapsack
    return dp[n][W];
}

int main() {
    int n; // Number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n], W;

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, wt, val, n);
    printf("\nMaximum value in Knapsack = %d\n", maxValue);

    return 0;
}
