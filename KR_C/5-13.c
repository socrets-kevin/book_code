#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10
#define MAXLEN 200
#define MAXLINES 100

int get_line(char *, int);
void error(char *);

int main(int argc, char* argv[])
{
    int n;
    if (argc == 1) {
    	n = DEFAULT_LINES;
    }
    else if (argc == 2 && (*(argv[1])) == '-') {
    	n = atoi(argv[1] + 1);
    }
    else {
    	error("usage: tail [-n]");
    }

    char *line = malloc(MAXLEN * sizeof(char));
    char *line_pt[MAXLINES];
    int len;
    int line_number = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
    	line_pt[line_number] = line;
	line_number++;
	line = malloc(MAXLEN * sizeof(char));
    }

    if (line_number > MAXLINES) {
	line_number = MAXLINES;
    }
    
    if ((n < 1) || (n > line_number)) {
	n = line_number;
    }

    while (n > 0) {
    	printf("%s", line_pt[(line_number - n)]);
	n--;
    }
}

int get_line(char *s, int lim) {
    int c;
    int i;
    
    for (i = 0 ;(--lim) > 0 && (c = getchar()) != EOF && c != '\n'; i++) {
	s[i] = c;
    }
    
    if (c == '\n') {
	s[i] = c;
	i++;
    }
    s[i] = '\0';
    return i;
}

void error(char *s) {
    printf("%s\n", s);
    exit(1);
}
