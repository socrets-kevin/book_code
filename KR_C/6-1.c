#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define KEYNUMBER 11

struct key {
    char *word;
    int count;
} key_tab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

int get_word(char *, int);
struct key *bin_search(char *, struct key *, int);

int main()
{
    char word[MAXWORD];
    struct key *p;

    while ((get_word(word, MAXWORD)) != EOF) {
	if (isalpha(word[0])) {
	    if ((p = bin_search(word, key_tab, KEYNUMBER)) != NULL) {
		p -> count++;
	    }
	}
    }

    for (p = key_tab; p < (key_tab + KEYNUMBER); p++) {
	if (p -> count > 0) {
	    printf("%4d %s\n", p -> count, p -> word);
	}
    }
    return 0;
}

struct key *bin_search(char* word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
	mid = low + (high - low) / 2;
	cond = strcmp(word, (mid -> word));
	
	if (cond < 0) {
	    high = mid - 1;
	}
	else if (cond > 0) {
	    low = mid + 1;
	}
	else {
	    return mid;
	}
    }
    return NULL;
}

#define BUFFERSIZE 1000

char buffer[BUFFERSIZE];
int buffer_postion = 0;

int get_ch(void) {
    if (buffer_postion > 0) {
	buffer_postion--;
	return buffer[buffer_postion];
    }
    else {
	return getchar();
    }
}

void unget_ch(int c) {
    if (buffer_postion > BUFFERSIZE) {
	printf("unget_ch: too many characters in buffer");
    }
    else {
	buffer[buffer_postion] = c;
	buffer_postion++;
    }
}

int get_word(char* word, int lim) {
    int c;

    do
    {
	c = get_ch();
    } while (isspace(c));

    int i = 0;
    if (c != EOF) {
	word[i] = c;
	i++;
    }
    if (!isalpha(c)) {
	word[i] = '\0';
	return c;
    }

    while (lim-- > 0) {
	word[i] = get_ch();
	if (!isalnum(word[i])) {
	    unget_ch(word[i]);
	    break;
	}
	i++;
    }
    word[i] = '\0';

    return word[0];
}
