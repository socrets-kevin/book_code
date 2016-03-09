#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXOP  100
#define NUMBER  '0'
#define NAME 'n'

void math_func(char s[]);
int get_operater(char []);
void push(double f);
double pop(void);
void clear(void);

int main()
{
    char s[MAXOP];
    int type;
    double first_pop;
    double second_pop;

    while ((type = get_operater(s)) != EOF) {
	switch (type) {
	case NUMBER: {
	    push(atof(s));
	    break;
	}
	case NAME: {
	    math_func(s);
	    break;
	}
	case '+': {
	    push(pop() + pop());
	    break;
	}
	case '-': {
	    first_pop = pop();
	    push(pop() - first_pop);
	    break;
	}
	case '*': {
	    push(pop() * pop());
	    break;
	}
	case '/': {
	    first_pop = pop();
	    if (first_pop != 0.0) {
		push(pop() / first_pop) ;
	    }
	    else {
		printf("error, divsion zero\n");
	    }
	    break;
	}
	/* for excercise 4-3 add fmod */
	case '%': {
	    first_pop = pop();
	    if (first_pop != 0.0) {
		push(fmod(pop(), first_pop));
	    }
	    else {
		printf("error, division zero\n");
	    }
	    break;
	}
        /* add stack manipulate for excercise 4-4 */
	case '?': {
	    first_pop = pop();
	    printf("\t%.8g\n", first_pop);
	    push(first_pop);
	    break;
	}
	case 'c': {
	    clear();
	    break;
	}
	case 's': {
	    first_pop = pop();
	    second_pop = pop();
	    push(first_pop);
	    push(second_pop);
	    break;
	}
	case 'd': {
	    first_pop = pop();
	    push(first_pop);
	    push(first_pop);
	    break;
	}
	case '\n': {
	    printf("\t%.8g\n", pop());
	    break;
	}
	default: {
	    printf("nuknown operater command %s\n", s);
 	    break;
	}
	}
    }

    return 0;
}

/* check s for math function */
void math_func(char s[]) {
    double first_pop;

    if (strcmp(s, "sin")) {
	push(sin(pop()));
    }
    else if (strcmp(s, "cos")) {
	push(cos(pop()));
    }
    else if (strcmp(s, "pow")) {
	first_pop = pop();
	push(pow(pop(), first_pop));
    }
    else if (strcmp(s, "exp")) {
	push(exp(pop()));
    }
    else {
	printf("error: %s not supporte\n", s);
    }
}

#define MAXVAL 100
int stack_position = 0;
double val[MAXVAL];

void push(double f) {
    if (stack_position < MAXVAL) {
	/* val[stack_position++] = f; */
	val[stack_position] = f;
	stack_position = stack_position + 1;
    }
    else {
	printf("stack full can not push %g\n", f);
    }
}

double pop(void) {
    if (stack_position > 0) {
	/* return val[--stack_position]; */
	stack_position = stack_position - 1;
	return val[stack_position];
    }
    else {
	printf("stack empty");
	return 0.0;
    }
}

void clear(void) {
    stack_position = 0;
}

#include <ctype.h>
int get_character();
void unget_character();

int get_operater(char s[]) {
    int character;
    /* rewrite the empty loop */
    /* while ((s[0] = character = get_character()) == ' ' || character == '\t') { */
    /* 	; */
    /* } */
    do
    {
	character = get_character();
	s[0] = character;
    } while (character == ' ' || character == '\t');
    s[1] = '\0';

    int i = 0;
    /* sin exp pow support  */
    if (islower(character)) {
	do
	{
	    i += 1;
	    character = get_character();
	    s[i] = character;
	} while (islower(character));
	s[i] = '\0';
	if (character != EOF) {
	    unget_character(character);
	}
	if (strlen(s) > 0) {
	    return NAME;
	}
	else {
	    return character;
	}
    }

    if (!isdigit(character) && character != '.' && character != '-') {
	return character;
    }
    
    /* negative sign support */
    if (character == '-') {
	character = get_character();
	if (isdigit(character)) {
	    i += 1;
	    s[i] = character;
	}
	else {
	    if (character != EOF) {
		unget_character(character);
	    }
	    return '-';
	}
    }
    
    if (isdigit(character)) {
	/* while (isdigit(s[++i] = character = get_character())) { */
	/*     ; */
	/* } */
	do
	{
	    character = get_character();
	    i += 1;
	    s[i] = character;
	} while (isdigit(character));
    }
    if (character == '.') {
	/* while (isdigit(s[++i] = character = get_character())) { */
	/*     ; */
	/* } */
	do
	{
	    character = get_character();
	    i += 1;
	    s[i] = character;
	} while (isdigit(character));
    }
    s[i] = '\0';
    if (character != EOF) {
	unget_character(character);
    }
    return NUMBER;
}

#define BUFFERSIZE 100
char buffer[BUFFERSIZE];
int buffer_position = 0;

int get_character() {
    /* return (buffer_position > 0) ? buffer[--buffer_position] : getchar(); */
    if (buffer_position > 0) {
	buffer_position -= 1;
	return buffer[buffer_position];
    }
    else {
	return getchar();
    }
}

void unget_character(int character) {
    if (buffer_position > BUFFERSIZE) {
	printf("ungetch: too many characters\n");
    }
    else {
	/* buffer[buffer_position++] = character; */
	buffer[buffer_position] = character;
	buffer_position += 1;
    }
}
