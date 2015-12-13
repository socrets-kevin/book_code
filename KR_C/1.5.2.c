#include <stdio.h>

main()
{
    double character_number;

    for (character_number = 0; getchar() != EOF; ++character_number) {
        ;
    }
    printf ("\n%.0f\n", character_number);
}
