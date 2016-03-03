#include <ctype.h>

/* enhance for atof can handle like 123.0e7 */

double atof(char s[]) {
    int i;
    for (i = 0; isspace(s[i]); i++) {
	;
    }
    int sign;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
	i++;
    }
    double val;
    for (val = 0.0; isdigit(s[i]); i++) {
	val = val * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.') {
	i++;
    }
    double power;
    for (power = 1.0; isdigit(s[i]); i++) {
	val = val * 10.0 + (s[i] - '0');
	power += 10.0;
    }
    val = sign * val * power;
    int exp;
    if (s[i] == 'e' || s[i] == 'E') {
	sign = (s[++i] == '-') ? -1 : 1;
	if (s[++i] == '-') {
	    i++;
	}
	for (exp = 0.0; isdigit(s[i]); i++) {
	    exp = exp * 10.0 + (s[i] - '0');
	}
	if (sign == -1) {
	    while (--exp > 0) {
		val *= 10;
	    }
	}
	else {
	    val /= 10;
	}
    }
    return val;
}
