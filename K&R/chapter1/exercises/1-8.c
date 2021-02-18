#include <stdio.h>

int main(void) {
    int blanks = 0, tabs = 0, newLines = 0;

    for (int c = getchar(); c != EOF; c = getchar()) {
        if (c == ' ') {
            ++blanks;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == '\n') {
            ++newLines;
        }
    }
    printf("Blanks: %d\nTabs: %d\nNew Lines: %d\n", blanks, tabs, newLines);

    return 0;
}
