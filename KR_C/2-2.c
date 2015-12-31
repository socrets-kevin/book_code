#include <stdio.h>

main()
{
    char s[100];
    int i;
    int character;
    int lim;

    lim = 100;
    /*for (i = 0; i < lim - 1 && (character = getchar()) != '\n' && character != EOF; ++i) {*/
        /*s[i] = character;*/
    /*}*/
/*    if (character == '\n') {*/
        /*s[i] = character;*/
        /*++i;*/
    /*}*/
    /*s[i] = '\0';*/

    for(i = 0; i < lim - 1; ++i) {
        character = getchar();
        if (character != '\n') {
            if (character != EOF) {
                s[i] = character;
            }
        }
        else {
            break;
        }
    }
    printf ("%s\n", s);
}
