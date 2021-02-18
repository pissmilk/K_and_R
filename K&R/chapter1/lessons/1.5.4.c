#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c = '\t')      // This will result in an error, but the book says to do it
            state = OUT;                             // on the next exercise it says to find any bugs so I guess
        else if (state == OUT) {                     // that is why. I will leave it be for now.
            state = IN;                              
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
