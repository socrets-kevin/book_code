#include <stdio.h>
#include <string.h>

#define MAXLINE 2000
#define MAXLEN 100

char *pointer_text[MAXLINE];

int get_line(char *s, int lim);
char *alloc(int n);
int read_lines(char *pointer_text[], int max_line);
void write_lines(char *pointer_text[], int line_number);

int main()
{
    int line_number;
    if ((line_number = read_lines(pointer_text, MAXLINE)) > 0) {
	write_lines(pointer_text, line_number);
    }
    else {
	printf("too many lines");
    }

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
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
	*s = c;
	s++;
    }
    if (c == '\n') {
	*s = c;
	s++;
	i++;
    }
    *s = '\0';
    return i;
}

int read_lines(char *pointer_text[], int max_line) {
    char *line = alloc(MAXLEN);
    int line_number;
    int len;

    line_number = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
	if (line_number > max_line) {
	    return -1;
	}
	else {
	    line[len - 1] = '\0';
	    pointer_text[line_number++] = line;
	}
	line = alloc(MAXLEN);
    }
    return line_number;
}

void write_lines(char *pointer_text[], int line_number) {
    int i;

    for (i = 0; i < line_number; i++) {
	printf("%s\n", pointer_text[i]);
    }

}


