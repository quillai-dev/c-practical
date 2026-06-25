/**
 * @file    t10.c
 * @brief   Theme 10, Task 4 -- String processing
 *
 * Find the longest word and the longest phrase in a given text.
 * A phrase is a sequence of characters between sentence terminators.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 1024
#define MAXWORD 64

int main(void)
{
    char text[MAXLEN];
    printf("Enter text (one line):\n");
    fgets(text, MAXLEN, stdin);

    char longestWord[MAXWORD] = "";
    char curWord[MAXWORD] = "";
    int wlen = 0, maxWlen = 0;

    char longestPhrase[MAXLEN] = "";
    char curPhrase[MAXLEN] = "";
    int plen = 0, maxPlen = 0;

    int n = (int)strlen(text);
    for (int i = 0; i <= n; i++) {
        char c = (i < n) ? text[i] : '\0';

        if (isalpha((unsigned char)c)) {
            if (wlen < MAXWORD-1) curWord[wlen++] = c;
        } else {
            curWord[wlen] = '\0';
            if (wlen > maxWlen) {
                maxWlen = wlen;
                strcpy(longestWord, curWord);
            }
            wlen = 0;
        }

        if (c == '.' || c == '!' || c == '?' || c == '\0') {
            curPhrase[plen] = '\0';
            if (plen > maxPlen) {
                maxPlen = plen;
                strcpy(longestPhrase, curPhrase);
            }
            plen = 0;
        } else if (plen < MAXLEN-1) {
            curPhrase[plen++] = c;
        }
    }

    printf("Longest word: \"%s\" (%d letters)\n", longestWord, maxWlen);
    printf("Longest phrase: \"%s\"\n", longestPhrase);
    return 0;
}
