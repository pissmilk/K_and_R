/* MIT License
 *
 * Copyright (c) 2021 Brighton Sikarskie
 *  
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <sys/ioctl.h>

const unsigned int max = 10;

int uintLen(unsigned int);

int main(void) 
{
    unsigned int wordLengths[max + 1] = {0}; // + 1 because I am going to keep track of words over the max
    unsigned int width = 4, highestFreq = 0;

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    for (unsigned int i = max; i >= 10; i /= 10) {
        ++width;
    }

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

    for (unsigned int i = 0; i <= max; ++i) {
        if (wordLengths[i] > highestFreq) {
            if (wordLengths[i] > w.ws_col) {
                highestFreq = w.ws_col - (width*2) - 1;
            } else {
                highestFreq = wordLengths[i];
            }
        }
    }

    // horizontal histogram version 1
    for (unsigned int i = 0; i <= max; ++i) {
        if (i != max) {
            printf("%*d: ", width, i + 1);
        } else {
            printf(" > %d: ", max);
        }
        if (wordLengths[i] > w.ws_col - (1 + uintLen(wordLengths[i]))) {
            for (unsigned int o = 0; o < w.ws_col - (7 + uintLen(wordLengths[i]) + width); ++o) {
                putchar('#');
            }
            printf("...# %d", wordLengths[i]);
        } else {
            for (unsigned int o = 0; o < wordLengths[i]; ++o) {
                putchar('#');
            }
            if (highestFreq == wordLengths[i]) {
                printf(" %d", wordLengths[i]);
            } else {
                printf(" %*d", highestFreq + uintLen(highestFreq) - wordLengths[i], wordLengths[i]);
            }
        }
        putchar('\n');
    }

    return 0;
}

int uintLen(unsigned int x) {
    if (x >= 1000000000) {
        return 10;
    }
    if (x >= 100000000) {
        return 9;
    }
    if (x >= 10000000) {
        return 8;
    }
    if (x >= 1000000) {
        return 7;
    }
    if (x >= 100000) {
        return 6;
    }
    if (x >= 10000) {
        return 5;
    }
    if (x >= 1000) {
        return 4;
    }
    if (x >= 100) {
        return 3;
    } 
    if (x >= 10) {
        return 2;
    }
    return 1;
}
