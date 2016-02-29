void expand(char s1[], char s2[]) {
    char character;
    int i, j;

    i = j = 0;
    while ((character = s1[i++]) != '\0') {
	if (s1[i] == '-'  && s1[i+1] >= character) {
	    i++;
	    while (character < s1[i]) {
		s2[j++] = character++;
	    }
	}
	else {
	    s2[j++] = character;
	}
    }
    s2[j] = '\0';
}
