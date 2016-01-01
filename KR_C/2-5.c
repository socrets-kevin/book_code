#include <stdio.h>

main()
{
    char s[] = "abcde";
    char pattern[] = "bdb";

    printf("%d\n", any(s, pattern));
}

int any(char s[], char pattern[])
{
    int i;
    int j;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; pattern[j] != '\0'; j++) {
            if (s[i] == pattern[j]) {
                return i;
            }
        }
    }
    return -1;
}
