#include <stdio.h>

/*main() */
/*{*/
    /*int fahr, celsius;*/
    /*int lower, upper, step;*/
    
    /*lower = 0;*/
    /*upper = 300;*/
    /*step = 20;*/

    /*fahr = lower;*/

    /*printf("transfer fahr to celsius\n");*/

    /*while(fahr <= upper) {*/
        /*celsius = 5 * (fahr - 32)/9;*/
        /*printf("%3d\t%3d\n", fahr, celsius);*/
        /*fahr = fahr + step;*/
    /*}*/
/*}*/

#define LOWER 0
#define UPPER 300
#define STEP 20

/*main() */
/*{*/
    /*float fahr, celsius;*/

    /*for (fahr = LOWER; fahr < UPPER; fahr = fahr + STEP) {*/
        /*celsius = 5 * (fahr - 32) / 9;*/
        /*printf("%6.1f\t%6.1f\n", fahr, celsius);*/
    /*}*/
/*}*/

float fahr_celsius(float fahr);

int main() 
{
    float fahr;

    for (fahr = LOWER; fahr < UPPER; fahr = fahr + STEP) {
        printf ("%6.1f\t%6.1f\n", fahr, fahr_celsius(fahr));
    }
}

float fahr_celsius(float fahr) 
{
    float celsius;

    celsius = 5 * (fahr - 32) / 9;
    return celsius;
}
