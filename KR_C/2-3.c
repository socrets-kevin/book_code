#include <stdio.h>

#define YES 1
#define NO 0

int hex_to_int(char s[]);

main() 
{
    char s[100];
    int character;
    int i;

    for (i = 0; (character = getchar()) != EOF && character != '\n'; ++i) {
        s[i] = character;
    }
    /*printf("%s\n", s);*/
    hex_to_int(s);
}

int hex_to_int(char s[]){
    int hex_digit;
    int i;
    int inhex;
    int n;

    i = 0;
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X') {
            ++i;
        }
    }
    n = 0;
    inhex = YES;
    for (; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            hex_digit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            hex_digit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            hex_digit = s[i] - 'A' + 10;
        }
        else {
            inhex = NO;
        }
        if (inhex == YES) {
            n = 16 * n + hex_digit;
        }
    }

    printf("%d\n", n);
}
