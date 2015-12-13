#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse_line(char s[]);

main()
{
    char line[MAXLINE];

    if (get_line(line, MAXLINE) > 0) {
        reverse_line(line);
        printf("result: %s", line);
    }
}

int get_line(char s[], int lim)
{
    int i;
    int character;

    for (i = 0; i < lim -1 && (character = getchar()) != '\n' && character != EOF; ++i) {
        s[i] = character;
    }
    if (character == '\n') {
        s[i] = character;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse_line(char s[]) 
{
    int i;
    int j;
    char temp;

    i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;
    if (s[i] == '\n') {
        --i;
    }
    j = 0;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}
