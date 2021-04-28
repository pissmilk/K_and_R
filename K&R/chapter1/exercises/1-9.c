#include <stdio.h>

int main(void) {
    for (int c = getchar(), prevC = '\0'; c != EOF; c = getchar()) {
        if (c != ' ' || prevC != ' ') {
            putchar(c);
            prevC = c;
        }
    }

    return 0;
}
