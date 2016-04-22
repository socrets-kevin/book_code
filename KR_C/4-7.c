#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 100

char buffer[BUFFERSIZE];
int buffer_postion = 0;

void unget_ch(int c) {
    if (buffer_postion > BUFFERSIZE) {
	printf("unget_ch: too many characters");
    }
    else {
	buffer[buffer_postion] = c;
	buffer_postion += 1;
    }
}

void ungets(char s[]) {
    int len = strlen(s);

    while (len > 0) {
	unget_ch(s[len]);
	len--;
    }
}
