#include <stdio.h>

int main() {
    float side, area;

    printf("Side:");
    scanf("%f", &side);

    area = side * side;

    printf("Area: %0.2f", area);

}