#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main() 
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while (len = get_line(line, MAXLINE) > 0) {
        printf ("%d, %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("\n%s", longest);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int character, i, j;

    j = 0;
    for (i = 0; (character = getchar()) != EOF && character != '\n'; ++i) {
        if (i < (lim - 2)) {
            s[j] = character;
            ++j;
        }
        if (character == '\n') {
            s[j] = character;
            ++j;
            ++i;
        }
    }
    s[j] = '\0';
    return i;
}

void copy(char to[], char from[]) 
{
    int i;

    i = 0;
    while (( to[i] = from[i]) != '\0') {
        ++i;
    }
}
