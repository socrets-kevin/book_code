#include <stdio.h>
#include <ctype.h>

int get_character();
void unget_character();

double get_float(double *point_number)
{
    int character;

    do
    {
	character = get_character();
    } while (isspace(character));

    int sign;
    if (!isdigit(character) && character != '+' && character != '-' && character != EOF) {
	unget_character(character);
	return 0;
    }
    if (character == '-') {
	sign = -1;
    }
    else {
	sign = 1;
    }
    for (*point_number = 0.0; isdigit(character); character = get_character()) {
	*point_number = 10.0 * (*point_number) + (character - '0');
    }
    if (character == '.') {
	character = get_character();
    }
    
    float power;
    for (power = 1.0; isdigit(character); character = get_character()) {
	*point_number = 10.0 * (*point_number) + (character - '0');
	power *= 10.0;
    }
    *point_number = sign * (*point_number) / power;
    if (character != EOF) {
	unget_character(character);
    }
    return character;
}

char buffer[100];
int buffer_position = 0;
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

