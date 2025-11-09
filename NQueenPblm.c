#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];

// Function to print the chessboard
void printSolution(int n) {
    printf("\nSolution:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Function to check if placing a queen is safe
int isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Check for same column or diagonal attack
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

// Recursive function to solve the N-Queen problem
void solveNQueen(int row, int n) {
    if (row > n) {
        printSolution(n);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;  // Place queen
            solveNQueen(row + 1, n);  // Try next row
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    if (n < 4) {
        printf("No solution exists for %d-Queens problem.\n", n);
        return 0;
    }

    solveNQueen(1, n);
    return 0;
}
