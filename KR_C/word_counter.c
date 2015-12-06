#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    /*int character, line_number, word_number, character_number, state;*/
    int character;
    int line_number;
    int word_number;
    int character_number;
    int state;

    line_number = word_number = character_number = 0;
    state = OUT;
    while ((character = getchar()) != EOF) {
        ++character_number;
        if (character == '\n') {
            ++line_number;
        }
        if (character == ' ' || character == '\n' || character == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++word_number;
        }
    }

    printf ("\n%d %d %d\n", character_number, line_number, word_number);
}
