#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0


main()
{
    int character;
    int character_number;
    int state;
    int max_value;
    int over_flow;
    int word_length_counter[MAXWORD];
    int i;
    int len;

    state = OUT;
    character_number = 0;
    over_flow = 0;
    for (i = 0; i < MAXWORD; i++) {
        word_length_counter[i] = 0;
    }
    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\n' || character == '\t') {
            state = OUT;
            if (character_number > 0) {
                if (character_number < MAXWORD) {
                    ++word_length_counter[character_number];
                }
                else {
                    ++over_flow;
                }
            }
        }
        else if (state == OUT) {
            state = IN;
            character_number = 1;
        }
        else {
            ++character_number;
        }
    }
    max_value = 0;
    for (i = 0; i < MAXWORD; i++) {
        if (word_length_counter[i] > max_value) {
            max_value = word_length_counter[i];
        }
    }
    for (i = 0; i < MAXWORD; i++) {
        printf ("\n%5d,%5d :\n", i, word_length_counter[i]);
        if (word_length_counter[i] > 0) {
            if ((len = word_length_counter[i] * MAXHIST / max_value) <= 0) {
                len = 1;
            }
            else {
                len = 0;
            }
            while (len > 0) {
                putchar ('*');
                --len;
            }
            putchar ('\n');
        }
    }
    if (over_flow > 0) {
        printf ("There are %d words >= %d \n", over_flow, MAXWORD);
    }
}
