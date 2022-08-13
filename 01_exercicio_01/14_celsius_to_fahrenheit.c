#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Celsius degress:");
    scanf("%Ff", &celsius);

    fahrenheit = (9 * celsius + 160) / 5;

    printf("%0.2f celsius degress is equals to %0.2f fahrenheit degress", celsius, fahrenheit);
}