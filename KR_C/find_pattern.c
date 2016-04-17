#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_line(char *line, int max);

int main(int argc, char *argv[])
{
    char *line = (char *)malloc(sizeof(char));
    int found = 0;

    if (argc != 2) {
    	printf("Usage: find pattern\n");
    }
    else {
    	while (get_line(line, MAXLINE) > 0) {
    	    if (strstr(line, argv[1]) != NULL) {
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
