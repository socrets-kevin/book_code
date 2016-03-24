void string_cat(char *s, char *t) {
    while (*s != '\0') {
	s++;
    }

    while ((*s = *t) != '\0') {
	s++;
	t++;
    }
}
