#include <stdio.h>

int main(void) {
    for (int c = getchar(); c != EOF; c = getchar()) {
        if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
        } else {
            putchar(c);
        }
    }

    return 0;
}
