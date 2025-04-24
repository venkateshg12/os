#include <stdio.h>
#include <limits.h>
#include<stdbool.h>

void lru(int pages[], int n, int frames) {
    int frameArr[frames];   // Array to represent the frames
    int recentUse[frames];  // Tracks the most recent use of each page in the frame
    int faults = 0;         // Count of page faults

    // Initialize all frames as empty (-1) and recentUse as unused
    for (int i = 0; i < frames; i++) {
        frameArr[i] = -1;
        recentUse[i] = -1;
    }

    // Process each page in the sequence
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;

        // Check if the page is already in a frame
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == page) {
                found = true;
                recentUse[j] = i; // Update the recent use time
                break;
            }
        }

        if (!found) {
            // Page fault occurs
            faults++;

            // Find the least recently used page (smallest recentUse value)
            int lruIndex = 0;
            for (int j = 1; j < frames; j++) {
                if (recentUse[j] < recentUse[lruIndex]) {
                    lruIndex = j;
                }
            }

            // Replace the LRU page with the current page
            frameArr[lruIndex] = page;
            recentUse[lruIndex] = i; // Update the recent use time
        }

        // Print the current state of frames
        printf("Page %d: ", page);
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == -1)
                printf("[ ] ");
            else
                printf("[%d] ", frameArr[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
}

int main() {
    int n, frames;

    // Input: Number of pages in the reference string
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input: Number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Run the LRU algorithm
    printf("\nLRU Page Replacement Algorithm:\n");
    lru(pages, n, frames);

    return 0;
}