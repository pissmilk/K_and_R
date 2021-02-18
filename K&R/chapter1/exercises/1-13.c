#include <stdio.h>

const int max = 10;

int main(void) {
    int wordLengths[max + 1] = {0}; // + 1 because I am going to keep track of words over the max
    for (int c = getchar(), i = 0; c != EOF; c = getchar()) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (i > max) {
                ++wordLengths[max];
            } else {
                ++wordLengths[i-1];
            }
            i = 0;
        } else {
            ++i;
        }
    }

    // horizontal histogram version 1
    /*
    for (int i = 0; i <= max; ++i) {
        if (i != max) {
            printf("%5d: ", i + 1);
        } else {
            printf(" > %d: ", max);
        }
        for (int o = 0; o < wordLengths[i]; ++o) {
            putchar('#');
        }
        putchar('\n');
    }
    */

    // horizontal histogram version 2
    for (int i = 0; i <= max; ++i) {
        if (wordLengths[i] > 0) {
            if (i != max) {
                printf("%5d: ", i + 1);
            } else {
                printf(" > %d: ", max);
            }
            for (int o = 0; o < wordLengths[i]; ++o) {
                putchar('#');
            }
            putchar('\n');
        }
    }

    return 0;
}
