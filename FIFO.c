#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10
#define MAX_FRAMES 3

void fifoPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int index = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Page\tFrames\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[index] = page;
            index = (index + 1) % MAX_FRAMES;
            pageFaults++;
        }

        printf("%d\t", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);

    fifoPageReplacement(pages, n);

    return 0;
}
