#include <stdio.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 200

char *pointer_line_text[MAXLINES];
int get_line(char s[], int lim);
int read_lines(char *pointer_line_text[], int line_number);
void write_lines(char *pointer_line_text[], int line_number);
void quick_sort(char *v[], int left, int right);
char *allocate(int n);

int main()
{
    int line_number;

    if ((line_number = read_lines(pointer_line_text, MAXLINES)) >= 0) {
	printf("original input\n-----\n");
	write_lines(pointer_line_text, line_number);
    	quick_sort(pointer_line_text, 0, line_number-1);
	printf("\nsort lines by first alphabetical order\n-----\n");
    	write_lines(pointer_line_text, line_number);
    	return 0;
    }
    else {
    	printf("error: input too big to sort\n");
    	return 1;
    }
}


int get_line(char *s, int lim) {
    char character;
    int i;

    for (i = 0; i < (lim -1) && (character = getchar()) != EOF && character != '\n'; i++) {
	*s = character;
	s++;
    }

    if (character == '\n') {
	*s = character;
	s++;
	i++;
    }
    *s = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocate_buffer[ALLOCSIZE];
static char *allocate_point = allocate_buffer;

char *allocate(int n) {
    if (allocate_buffer + ALLOCSIZE - allocate_point > 0) {
	allocate_point += n;
	return allocate_point - n;
    }
    else {
	return 0;
    }
}


int read_lines(char *pointer_line_text[], int max_lines) {
    int len;
    int line_number;
    char *line = allocate(MAXLEN);

    line_number = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
	if (line_number > max_lines || line == NULL) {
	    break;
	}
	else {
	    line[len - 1] = '\0';
	    pointer_line_text[line_number++] = line;
	    line = allocate(MAXLEN);
	}
    }
    return line_number;
}

void write_lines(char *pointer_line_text[], int line_number) {
    int i;

    for (i = 0; i < line_number; i++) {
	printf("%s\n", pointer_line_text[i]);
    }

}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void quick_sort(char *v[], int left, int right) {
    int i, last;

    if (left >= right) {
	return;
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
	if (strcmp(v[i], v[left]) < 0) {
	    swap(v, ++last, i);
	}
    }
    swap(v, left, last);
    quick_sort(v, left, last - 1);
    quick_sort(v, last+1, right);
}
