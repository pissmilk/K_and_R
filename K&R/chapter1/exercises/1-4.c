#include <stdio.h>

int main(void) {
    float fahr = 0;

    puts("Celsius -> Fahrenheit");
    for (float celsius = 0; celsius <= 300; celsius += 20) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f\t\t%5.1f\n", celsius, fahr);
    }

    return 0;
}
