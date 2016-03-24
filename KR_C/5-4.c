void string_end(char *s, char *t) {
    char *begin_s = s;
    char *begin_t = t;
    
    while (*s != '\0') {
	s++;
    }
    while (*t != '\0') {
	t++;
    }
    while (*s == *t) {
	s--;
	t--;
	if (s == begin_s || t == begin_t) {
	    break;
	}
    }

    if (*s == *t && t == begin_t && *s != '\0') {
	return 1;
    }
    else {
	return 0;
    }
}
