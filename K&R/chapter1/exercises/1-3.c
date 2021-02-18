#include <stdio.h>

int main(void) {
    float celsius = 0;

    puts("Fahrenheit -> Celsius");
    for (float fahr = 0; fahr <= 300; fahr += 20) {
        celsius = (5. / 9.) * (fahr - 32.);
        printf("%3.0f\t\t%5.1f\n", fahr, celsius);
    }

    return 0;
}
