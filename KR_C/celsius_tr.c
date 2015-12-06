#include <stdio.h>

main()
{
    float celsius, fahr;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;

    printf ("transfer celsius to fahr\n");
    while(celsius <= upper){
        fahr = (9.0/5.0)*celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
