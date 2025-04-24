#include <stdio.h>
#include <stdbool.h>

void fifo(int pages[], int n, int frames) {
    int frameArr[frames]; // Array to represent the frames
    int faults = 0;       // Count of page faults
    int front = 0;        // Pointer to track the oldest page

    // Initialize all frames as empty (-1)
    for (int i = 0; i < frames; i++) {
        frameArr[i] = -1;
    }

    // Process each page
    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if the page is already in a frame
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // If the page is not found, replace the oldest page
        if (!found) {
            frameArr[front] = pages[i]; // Replace the page at 'front'
            front = (front + 1) % frames; // Move the pointer to the next frame
            faults++; // Increment page fault count
        }

        // Print current state of frames
        printf("Page %d: ", pages[i]);
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
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2,0,1,7,0,1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;

    printf("FIFO Page Replacement Algorithm:\n");
    fifo(pages, n, frames);

    return 0;
}