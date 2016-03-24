void string_copy(char *s, char *t) {
    int i = 0;

    while ((s[i] = t[i]) != '\0') {
	i++;
    }
}

void string_copy_v2(char *s, char *t) {
    while ((*s = *t) != '\0') {
	s++;
	t++;
    }
}
