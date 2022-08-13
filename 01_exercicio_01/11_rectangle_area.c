#include <stdio.h>

int main() {
    float width, heigth, area;

    printf("Width and height: ");
    scanf("%f %f", &width, &heigth);

    area = width * heigth;

    printf("Area: %0.2f", area);
}