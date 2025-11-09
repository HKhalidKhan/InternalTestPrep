#include <stdio.h>

// Structure to store job details
struct Job {
    int id;        // Job ID
    int deadline;  // Deadline for job
    int profit;    // Profit if job is done before or on deadline
};

// Function to swap two jobs
void swap(struct Job *a, struct Job *b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort jobs by profit in descending order
void sortJobs(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (jobs[i].profit < jobs[j].profit) {
                swap(&jobs[i], &jobs[j]);
            }
        }
    }
}

// Function to find maximum deadline among all jobs
int findMaxDeadline(struct Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

// Function to perform Job Sequencing
void jobSequencing(struct Job jobs[], int n) {
    // Sort jobs in descending order of profit
    sortJobs(jobs, n);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[maxDeadline];   // Array to store which job is done at which time
    int totalProfit = 0;

    // Initialize all slots to -1 (empty)
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;  // Assign job i to slot j
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Display the result
    printf("\nSelected Jobs (in order of execution): ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("J%d ", jobs[slot[i]].id);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter Job ID, Deadline, and Profit:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
