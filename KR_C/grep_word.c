#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int max);
int str_index(char source[], char search_for[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found;
    while (get_line(line, MAXLINE) > 0) {
	if (str_index(line, pattern) > 0) {
	    printf("%s", line);
	}
	found++;
    }
    return found;
}

int get_line(char s[], int lim) {
    int character, i;

    i = 0;
    while (--lim > 0 && (character = getchar()) != EOF && character != '\n') {
	s[i++] = character;
    }
    s[i] = '\0';
    return i;
}

int str_index(char s[], char t[]) {
    int i, j, k;

    i = 0;
    for (i = 0; s[i] != '\0'; i++) {
	for (j = i, k = 0; (s[j] == t[k] && t[k] != '\0'); j++, k++) {
	    ;
	}
	if (k > 0 && t[k] == '\0') {
	    return i;
	}
    }
    return -1;
}
