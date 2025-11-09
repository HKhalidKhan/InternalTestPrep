#include <stdio.h>

// Function for Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Element found, return index
        else if (arr[mid] < key)
            low = mid + 1; // Search in right half
        else
            high = mid - 1; // Search in left half
    }
    return -1; // Element not found
}

int main() {
    int n, i, key, result;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Perform binary search
    result = binarySearch(arr, n, key);

    // Display result
    if (result != -1)
        printf("Element %d found at position %d.\n", key, result + 1);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
