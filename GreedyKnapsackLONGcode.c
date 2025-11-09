#include <stdio.h>

// Structure to store weight, profit, and ratio
struct Item {
    float weight;
    float profit;
    float ratio;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by profit/weight ratio (descending order)
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                swap(&items[i], &items[j]);
            }
        }
    }
}

// Function to perform Greedy Knapsack
void greedyKnapsack(struct Item items[], int n, float capacity) {
    float totalProfit = 0.0;
    float currentWeight = 0.0;

    printf("\nItems selected:\n");
    printf("Weight\tProfit\tFraction\n");

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the full item
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("%.2f\t%.2f\t1.00\n", items[i].weight, items[i].profit);
        } else {
            // Take only fraction of the next item
            float remain = capacity - currentWeight;
            float fraction = remain / items[i].weight;
            totalProfit += items[i].profit * fraction;
            printf("%.2f\t%.2f\t%.2f\n", items[i].weight, items[i].profit, fraction);
            break; // Knapsack is full
        }
    }

    printf("\nTotal Profit = %.2f\n", totalProfit);
}

int main() {
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (weight profit): ", i + 1);
        scanf("%f %f", &items[i].weight, &items[i].profit);
        items[i].ratio = items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items by profit/weight ratio
    sortItems(items, n);

    // Perform Greedy Knapsack
    greedyKnapsack(items, n, capacity);

    return 0;
}
