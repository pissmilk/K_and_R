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
