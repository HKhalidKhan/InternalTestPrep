#include <stdio.h>

int n;               // Number of elements
int targetSum;       // Target sum
int set[20];         // Input set
int subset[20];      // To store current subset

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Recursive function for generating subsets
void sumOfSubsets(int i, int currentSum, int size) {
    // If current sum equals target, print the subset
    if (currentSum == targetSum) {
        printSubset(subset, size);
        return;
    }

    // If all elements are processed or sum exceeds target
    if (i >= n || currentSum > targetSum)
        return;

    // Include the current element
    subset[size] = set[i];
    sumOfSubsets(i + 1, currentSum + set[i], size + 1);

    // Exclude the current element
    sumOfSubsets(i + 1, currentSum, size);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &targetSum);

    printf("\nSubsets with the given sum are:\n");
    sumOfSubsets(0, 0, 0);

    return 0;
}
