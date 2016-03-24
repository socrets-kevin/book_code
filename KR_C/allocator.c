#define ALLOCSIZE 1000

char allocater_buffer[ALLOCSIZE];
char *allocater_pointer = allocater_buffer;

char *allocater(int n) {
    if (allocater_buffer + ALLOCSIZE - n > 0) {
	allocater_pointer += n;
	return allocater_pointer - n;
    }
    else {
	return 0;
    }
}

void afree(char *p) {
    if (p > allocater_buffer && p < allocater_buffer + ALLOCSIZE) {
	allocater_pointer = p;
    }
}
