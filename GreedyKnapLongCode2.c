#include <stdio.h>

// Structure for items
struct Item {
    int weight;
    int profit;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Greedy Knapsack
void greedyKnapsack(struct Item items[], int n, int capacity) {
    int i, j;
    float totalProfit = 0.0;

    // Calculate profit/weight ratio
    float ratio[n];
    for (i = 0; i < n; i++)
        ratio[i] = (float)items[i].profit / items[i].weight;

    // Sort items in descending order of profit/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(&items[i], &items[j]);
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
            }
        }
    }

    int currentWeight = 0;

    printf("\nItems taken in Knapsack:\n");
    printf("Item\tProfit\tWeight\tFraction\n");

    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("%d\t%d\t%d\t1.00\n", i + 1, items[i].profit, items[i].weight);
        } else {
            // Take fraction of the item
            int remain = capacity - currentWeight;
            float fraction = (float)remain / items[i].weight;
            totalProfit += items[i].profit * fraction;
            printf("%d\t%d\t%d\t%.2f\n", i + 1, items[i].profit, items[i].weight, fraction);
            break; // Knapsack is full
        }
    }

    printf("\nTotal Profit = %.2f\n", totalProfit);
}

int main() {
    int n, capacity, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d Profit: ", i + 1);
        scanf("%d", &items[i].profit);
        printf("Item %d Weight: ", i + 1);
        scanf("%d", &items[i].weight);
    }

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &capacity);

    greedyKnapsack(items, n, capacity);

    return 0;
}
