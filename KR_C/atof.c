#include <ctype.h>

int atof(char s[]) {
    int i;

    for (i = 0; isspace(s[i]); i++) {
	;
    }
    int sign;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
	i++;
    }
    double val, power;
    for (val = 0.0; isdigit(s[i]); i++) {
	val = val * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.') {
	i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
	val = val * 10.0 + (s[i] - '0');
	power += 10.0;
    }
    return sign * val / power;
}
