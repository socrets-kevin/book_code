#include <ctype.h>

int atoi(char s[])
{
    int sign, i;

    for (i = 0; isspace(s[i]); i++) {
	;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
	i++;
    }
    int n = 0;
    for (n = 0; isdigit(s[i]); i++) {
	n = n * 10 + (s[i] - '0');
    }
    return sign * n;
}
