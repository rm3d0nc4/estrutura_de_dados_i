#include <stdio.h>

int main() {
    float radius, length;

    const float pi = 3.14159265359;

    printf("Radius: ");
    scanf("%f", &radius);

    length = 2 * pi * radius;

    printf("Area: %0.2f", length);
}