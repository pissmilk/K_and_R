#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
/*
main()
{
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      // lower limit of temperature scale
    upper = 300;    // upper limit
    step = 20;      // step size

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        // printf("%d\t%d\n", fahr, celsius);
        printf("%3d %6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
*/

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;      // lower limit of temperature scale
    upper = 300;    // upper limit
    step = 20;      // step size

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}