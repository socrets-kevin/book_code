unsigned right_rot(unsigned x, int n) {
    int word_length(void);
    int right_digit;

    while (n -- > 0) {
	right_digit = (x & 1) << (word_length);
	x = x >> 1;
	x = right_digit | x;
    }
    return x;
}
