#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int len, max;

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("\nresult: %d, %s\n", len, longest);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int i;
    int character;

    for (i = 0; i < lim - 1 && (character = getchar()) != '\n' && character != EOF; ++i) {
        s[i] = character;
    }
    if (character == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0' ) {
        ++i;
    }
}
