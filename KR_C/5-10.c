#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

void push(double f);
double pop(void);
void unget_str(char *s);
int get_operater(char *s);

int main(int argc, char *argv[])
{
    char *s = (char *)malloc(sizeof(char) * MAXOP);

    while (--argc > 0) {
	unget_str(" ");
	unget_str(*(++argv));
	
	switch (get_operater(s)) {
	case NUMBER: {
	    push(atof(s));
	    break;
	}
	case '+': {
	    push(pop() + pop());
	    break;
	}
	case '-': {
	    double first_pop = pop();
	    push(pop() - first_pop);
	    break;
	}
	case '*': {
	    push(pop() * pop());
	    break;
	}
	case '/': {
	    double first_pop = pop();
	    if (first_pop != 0) {
		push(pop() / first_pop);
	    }
	    else {
		printf("error: divisor zero");
	    }
	    break;
	}
	default: {
	    printf("error: unknown command %s\n", s);
	    argc = 1;
	    break;
	}
	}
    }
    printf("\t%.8g\n", pop());
    return 0;
}

#define MAXVAL 100
int stack_position = 0;
double val[MAXVAL];

/* push in stack */
void push(double f) {
    if (stack_position < MAXVAL) {
	val[stack_position] = f;
	stack_position++;
    }
    else {
	printf("stack full can't push %g\n", f);
    }
}

/* pup up the last element of stack and return stack top element */
double pop(void) {
    if (stack_position > 0) {
	stack_position--;
	return val[stack_position];
    }
    else {
	printf("stack empty");
	return 0;
    }
}

#include <string.h>
#define BUFFERSIZE 1000

char buffer[BUFFERSIZE];
int buffer_position = 0;

int get_ch() {
    if (buffer_position > 0) {
	buffer_position--;
	return buffer[buffer_position];
    }
    else {
	return getchar();
    }
}

void unget_ch(int c) {
    if (buffer_position > BUFFERSIZE) {
	printf("unget_ch: too many characters");
    }
    else {
	buffer[buffer_position] = c;
	buffer_position++;
    }
}

void unget_str(char *s) {
    int len = strlen(s);

    while (len > 0) {
	len--;
	unget_ch(s[len]);
    }
}

#include <ctype.h>

int get_operater(char *s) {
    int c;

    do
    {
	c = get_ch();
	s[0] = c;
    } while (c == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.') {
	return c;
    }

    int i = 0;
    if (isdigit(c)) {
	do
	{
	    c = get_ch();
	    s[++i] = c;
	} while (isdigit(c));
    }
    if (c == '.') {
	do
	{
	    c = get_ch();
	    s[++i] = c;
	} while (isdigit(c));
    }
    s[i] = '\0';
    if (c != EOF) {
	unget_ch(c);
    }
    return NUMBER;
}
