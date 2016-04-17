#include <stdio.h>

int day_of_year(int year, int month, int day);

int main() {
    printf("%d\n", day_of_year(2016, 4, 16));
}


static char day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    if (year % 4 == 0 && year % 100 != 0) {
	leap = 1;
    }
    else if (year % 400 == 0) {
	leap = 1;
    }
    else {
	leap = 0;
    }

    for (i = 0; i < month; i++) {
	day += day_table[leap][i];
    }

    return day;
}

void month_day(int year, int year_day, int *month_p, int *day_p) {
    int i, leap;

    leap = (year%4 == 0 && year%100 !=0) || year%400 == 0;

    for(i = 0; year_day > day_table[leap][i]; i++) {
	year_day -= day_table[leap][i];
    }
    *month_p = i;
    *day_p = year_day;
}
