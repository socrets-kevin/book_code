/*'\t'有多少个空格就把'\t'换成相应数目的空格*/

#include <stdio.h>

#define TABINC 8

main()
{
    int position;
    int blank_number;
    int character;

    blank_number = 0;
    position = 1;
    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            blank_number = TABINC - (position - 1) % TABINC;
            while (blank_number > 0) {
                putchar(' ');
                ++position;
                --blank_number;
            }
        }
        else if (character == '\n') {
            putchar(character);
            position = 1;
        }
        else {
            putchar(character);
            ++position;
        }
    }
}

/*main() */
/*{*/
    /*int character;*/

    /*while((character = getchar()) != EOF) {*/
        /*if (character == '\t') {*/
            /*putchar(' ');*/
        /*}*/
        /*else {*/
            /*putchar(character);*/
        /*}*/
    /*}*/
/*}*/
