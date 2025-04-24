#include <stdio.h>

// Function to sort processes based on burst time and arrival time
void sortProcesses(int n, int process[], int arrival[], int burst[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst[j] > burst[j + 1]) {
                // Swap burst times
                int temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;

                // Swap arrival times
                temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;

                // Swap process IDs
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], arrival[n], burst[n], completion[n], turnaround[n], waiting[n];

    // Input arrival and burst times
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process P%d:\n", process[i]);
        printf("  Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("  Burst Time: ");
        scanf("%d", &burst[i]);
    }

    // Sort processes based on burst time
    sortProcesses(n, process, arrival, burst);

    // Calculate completion, turnaround, and waiting times
    completion[0] = arrival[0] + burst[0]; // Completion time of the first process
    for (int i = 1; i < n; i++) {
        if (completion[i - 1] < arrival[i]) {
            // If the previous process finishes before the current process arrives
            completion[i] = arrival[i] + burst[i];
        } else {
            // Otherwise, the current process starts immediately after the previous one finishes
            completion[i] = completion[i - 1] + burst[i];
        }
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i]; // Turnaround Time = Completion Time - Arrival Time
        waiting[i] = turnaround[i] - burst[i];     // Waiting Time = Turnaround Time - Burst Time
    }

    // Display results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               process[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    return 0;
}