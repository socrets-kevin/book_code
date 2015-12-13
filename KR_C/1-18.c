#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
int remove_bt(char s[]);

main()
{
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        if (remove_bt(line) > 0) {
            printf("\nresult: %s", line);
        }
    }
    return 0;
}

int get_line(char s[], int lim) 
{
    int i;
    int character;

    for (i = 0; i < lim - 1 && (character = getchar()) != '\n' && character != EOF; i++) {
        s[i] = character;
    }
    if (character == '\n') {
        s[i] = character;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int remove_bt(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\n') {
        ++i;
    }
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}
