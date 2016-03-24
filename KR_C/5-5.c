int string_len(char *s) {
    char *p = s;
    while (*p != '\0') {
	p++;
    }
    return p - s;
}

void string_copy(char *s, char *t, int n) {
   while (*t != '\0' && n-- > 0) {
       *s = *t;
       s++;
       t++;
   }
   while (n-- > 0) {
       *s = '\0';
       s++;
   }
}

void string_cat(char *s, char *t, int n) {
    string_copy(s + string_len(s), t, n);
}

int string_cmp(char *s, char *t, int n) {
    for (; *s == *t; s++, t++) {
	if (*s == '\0' || --n <= 0) {
	    return 0;
	}
    }
    return *s - *t;
}
