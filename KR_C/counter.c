#include <stdio.h>

main()
{
    int character;
    int i;
    int white_number;
    int other_number;
    int digit_number[10];

    white_number = other_number = 0;
    for (i = 0; i < 10; i++) {
        digit_number[i] = 0;
    }

    while ((character = getchar()) != EOF) {
        if (character >= '0' && character <= '9') {
            ++digit_number[character - '0'];
        }
        else if (character == ' ' || character == '\n' || character == '\t') {
            ++white_number;
        }
        else {
            ++other_number;
        }
    }

    printf("\ndigits number: ");
    for (i = 0; i < 10; i++) {
        printf("%d, ", digit_number[i]);
    }
    printf("white numbers, %d, other numbers, %d\n", white_number, other_number);
}
