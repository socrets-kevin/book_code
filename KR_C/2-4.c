#include <stdio.h>

void squeeze(char s[], char del[]);

main()
{
    char s[] = "abcdef";
    char del[] = "be";

    squeeze(s, del);
    printf("%s\n", s);
}

void squeeze(char s[], char del[]) {
    int i;
    int j;
    int k;

    for (i = k = 0; s[i] != '\0'; i++) {
        for (j = 0; del[j] != '\0' && s[i] != del[j]; j++) {
            ;
        }
        if (del[j] == '\0') {
            s[k] = s[i];
            k++;
        }
    }
    s[k] = '\0';
}
