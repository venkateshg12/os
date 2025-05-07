#include <stdio.h>

// Function to calculate waiting time, turnaround time, and completion time
void calculateTimes(int n, int arrival[], int burst[], int completion[], int turnaround[], int waiting[]) {
    // Completion time of the first process is equal to its burst time
    completion[0] = arrival[0] + burst[0];
    
    // Calculate completion time for all processes
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
}

// Function to display results
void displayResults(int n, int process[], int arrival[], int burst[], int completion[], int turnaround[], int waiting[]) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               process[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
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

    // Calculate completion, turnaround, and waiting times
    calculateTimes(n, arrival, burst, completion, turnaround, waiting);

    // Display results
    displayResults(n, process, arrival, burst, completion, turnaround, waiting);

    return 0;
}