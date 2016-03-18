#include <ctype.h>
#include <stdio.h>

int get_character(void);
void unget_character(int);

int get_int(int *point_number) {
    int character;
    int sign;

    do
    {
	character = get_character();
    } while (isspace(character));

    if (!isdigit(character) && character != EOF && character != '+' && character != '-') {
	unget_character(character);
	return 0;
    }
    if (character == '-') {
	sign = -1;
    }
    else {
	sign = 1;
    }

    int double_sign;
    if (character == '+' || character == '-') {
	/* support for exercise 5-1 */
	double_sign = character;
	character = get_character();
	if (!isdigit(character)) {
	    if (character != EOF) {
		unget_character(character);
	    }
	    unget_character(double_sign);
	}
	return double_sign;
    }
    for (*point_number = 0; isdigit(character); character = get_character()) {
	*point_number = (*point_number) * 10 + (character - '0');
    }
    *point_number = (*point_number) * sign;
    if (character != EOF) {
	unget_character(character);
    }
    return character;
}

int buffer_position = 0;
char buffer[100];

int get_character(void) {
    if (buffer_position > 0) {
	buffer_position -= 1;
	return buffer[buffer_position];
    }
    else {
	return getchar();
    }
}

void unget_character(int character) {
    buffer_position += 1;
    buffer[buffer_position] = character;
}
