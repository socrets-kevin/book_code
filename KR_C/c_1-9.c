#include <stdio.h>

#define NONBLANK 'a'

main()
{
    int character, previous_character;

    previous_character = NONBLANK;
    while((character = getchar()) != EOF) {
        if (character != ' ') {
            putchar(character);
        }
        else if (previous_character != ' ') {
            putchar(character);
        }
        previous_character = character;
    }
}
