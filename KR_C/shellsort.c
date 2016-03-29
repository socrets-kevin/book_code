#include <stdio.h>

void shell_sort(int v[], int n);

int main()
{
    int v[] = {2, 5, 3, 10};
    shell_sort(v, 4);
    for (int i = 0; i < 4; i++) {
	printf("%d\n", v[i]);
    }
}

void shell_sort(int v[], int n) {
    int temp, i, j, gap;

    for (gap = n/2 ; gap > 0; gap /= 2) {
	for (i = gap; i < n; i++) {
	    for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
		temp = v[j];
		v[j] = v[j+gap];
		v[j+gap] = temp;
	    }
	}
    }
}
