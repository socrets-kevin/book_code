#include <stdio.h>

#define MAXLINE 1000

int get_line(char *s, int lim);

int main()
{
    char *line;

    printf("%d\n", get_line(line, MAXLINE));

}

#define ALLOCSIZE 10000

static char alloc_buffer[ALLOCSIZE];
static char *alloc_p = alloc_buffer;

char *alloc(int n) {
    if (alloc_buffer + ALLOCSIZE - alloc_p > n) {
	alloc_p += n;
	return alloc_p - n;
    }
    else {
	return 0;
    }
}

void afree(char *p) {
    if (p >= alloc_buffer && p < alloc_buffer + ALLOCSIZE) {
	alloc_p = p;
    }
}

int get_line(char *s, int lim) {
    char c;
    int i;
    
    s = alloc(MAXLINE);
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
	*s = c;
	s++;
    }
    if (c == '\n') {
	*s = c;
	s++;
    }
    i++;
    *s = '\0';
    return i;
}
