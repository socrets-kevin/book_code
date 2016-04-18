#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_line(char *s, int lim);

int main(int argc, char *argv[])
{
    char *line = (char *)malloc(sizeof(char));
    long line_no = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (* ++argv)[0] == '-') {
	while (c = *++argv[0]) {
	    switch (c) {
	    case 'x': {
		except = 1;
		break;
	    }
	    case 'n': {
		number = 1;
		break;
	    }
	    default:{
		printf("find: illegal option %c\n", c);
		argc = 0;
		found = -1;
		break;
	    }
	    }
	}
    }
    if (argc != 1) {
	printf("Usage: find -x -n pattern\n");
    }
    else {
	while (get_line(line, MAXLINE) > 0) {
	    line_no++;
	    if ((strstr(line, *argv) != NULL) != except) {
		if (number) {
		    printf("%ld:", line_no);
		}
		printf("%s", line);
		found++;
	    }
	}
    }
    return found;
}

int get_line(char *s, int lim) {
    char c;
    int i = 0;
    
    while ((lim--) > 0 && (c = getchar()) != EOF && c != '\n') {
	*s = c;
	s++;
	i++;
    }
    if (c == '\n') {
	*s = c;
	s++;
	i++;
    }
    *s = '\0';
    return i;
}

