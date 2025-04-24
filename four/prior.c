#include <stdio.h>
#include <limits.h>

void priority(int pid[], int at[], int bt[], int p[], int size) {
    int remaining_time[size];
    int current_time = 0;
    int completed = 0;

    // Initialize remaining time for each process
    for (int i = 0; i < size; i++) {
        remaining_time[i] = bt[i];
    }

    printf("Process\tArrival Time\tBurst Time\tPriority\completion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < size) {
        int selected = -1;
        int highest_priority = INT_MAX; // Smallest priority value means highest priority

        // Find the process with the highest priority that has arrived and not completed
        for (int i = 0; i < size; i++) {
            if (at[i] <= current_time && remaining_time[i] > 0 && p[i] < highest_priority) {
                selected = i;
                highest_priority = p[i];
            }
        }

        if (selected == -1) {
            // If no process is available, increment time
            current_time++;
        } else {
            // Execute the selected process for 1 unit of time
            remaining_time[selected]--;
            current_time++;

            if (remaining_time[selected] == 0) {
                // Process completed
                completed++;
                int finish_time = current_time;
                int turnaround_time = finish_time - at[selected];
                int waiting_time = turnaround_time - bt[selected];

                // Print details of the completed process
                printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                       pid[selected], at[selected], bt[selected], p[selected],
                       finish_time, turnaround_time, waiting_time);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], at[n], bt[n], p[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for P%d: ", process[i]);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", process[i]);
        scanf("%d", &bt[i]);
        printf("Enter priority for P%d: ", process[i]);
        scanf("%d", &p[i]);
    }

    printf("\nPreemptive Priority Scheduling:\n");
    priority(process, at, bt, p, n);

    return 0;
}