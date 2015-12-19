#include <stdio.h>
#define TABINC 8

main()
{
    int blank_number;
    int tab_number;
    int position;
    int character;

    blank_number = 0;
    tab_number = 0;
    for (position = 1; (character = getchar()) != EOF; ++position) {
        if (character == ' ') {
            if (position % TABINC != 0) {
                ++blank_number;
            }
            else {
                blank_number = 0;
                ++tab_number;
            }
        }
        else {
            for ( ; tab_number > 0; --tab_number) {
                putchar('\t');
            }
            if (character == '\t') {
                blank_number = 0;
            }
            else {
                for ( ; blank_number > 0; --blank_number) {
                    putchar(' ');
                }
            }
            putchar(character);
            if (character = '\n') {
                position = 0;
            }
            else if (character == '\t') {
                position = position + (TABINC - (position - 1) % TABINC) - 1;
           }

        }
    }
    
}
