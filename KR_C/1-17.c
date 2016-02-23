#include <stdio.h>
#define MAXLINE 1000
#define CHARNUM 10

int get_line(char line[], int maxline);

int main() 
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > CHARNUM) {
            printf("\nresult: %s", line);
        }
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
        s[i] = character;
        ++i;
    }
    s[i] = '\0';
    return i;
}


