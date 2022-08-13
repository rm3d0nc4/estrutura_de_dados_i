#include <stdio.h>

int main() {
    float base, height, area;

    printf("Base and height: ");
    scanf("%f %f", &base, &height);

    area = base * height;

    printf("Area: %0.2f", area);
}