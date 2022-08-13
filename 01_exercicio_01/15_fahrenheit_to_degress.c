#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("Fahrenheit degress:");
    scanf("%Ff", &fahrenheit);

    celsius = (5 * fahrenheit - 160) / 9;

    printf("%0.2f fahrenheit degress is equals to %0.2f celsius degress", fahrenheit, celsius);
}