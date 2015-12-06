#include <stdio.h>

#define OUT 0
#define IN 1

main()
{
    int character;
    int state;

    state = OUT;
    while ((character = getchar()) != EOF) {
        if (character == '\n' || character == '\t' || character == ' ') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        }
        else if (state == OUT) {
            state = IN;
            putchar(character);
        }
        else {
            putchar(character);
        }
    }
}
