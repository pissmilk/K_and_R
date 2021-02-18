#include <stdio.h>

int main(void) {
    float fahr = 0;

    puts("Celsius -> Fahrenheit");
    for (float celsius = 0; fahr <= 300; fahr += 20) {
        //fahr = (celsius / (5. / 9.)) + 32.;
        printf("%3.0f\t\t%5.1f\n", celsius, fahr);
    }

    return 0;
}
