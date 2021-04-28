#include <stdio.h>
#include <sys/ioctl.h>

int main(void) {
    int freq['z' - 'a' + 1] = {0};
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    // continue tomorrow and add the terminal
    // size thingy where it wont wrap to the next line
    // like 1-13.c

    for (int c = getchar(); c != EOF; c = getchar()) {
        if (c >= 'A' && c <= 'Z') {
            ++freq[c - 'A'];
        } else if (c >= 'a' && c <= 'z') {
            ++freq[c - 'a'];
        }
    }

    for (int i = 0; i <= 'z' - 'a'; ++i) {
        printf("|%c%c|", i + 'A', i + 'a');
        for (int o = 0; o < freq[i]; ++o) {
            putchar('#');
        }
        putchar('\n');
    }

    return 0;
}
