#include <stdio.h>

int get_leap(int year) {
    int leap;
    leap = (year%4 == 0 && year%100 !=0) || year%400 == 0;
    return leap;
}

static char day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int year, int month, int day) {
    int leap;
    leap = get_leap(year);
    
    char *p;
    p = day_table[leap];

    while (--month > 0) {
	day += *(++p);
    }

    return day;
}

void month_day(int year, int year_day, int *month_p, int *day_p) {
    int leap;
    leap = get_leap(year);

    char *p;
    p = day_table[leap];

    while (year_day > *(++p)) {
	year_day -= *p;
    }
    *day_p = year_day;
    *month_p = p - *(day_table + leap);
}

