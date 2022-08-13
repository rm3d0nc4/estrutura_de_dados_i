#include <stdio.h>

int main() {
    float kg, g;

    printf("kg value: ");
    scanf("%f", &kg);

    g = kg * 1000;

    printf("%0.2f kg is equals to %0.2f grams", kg, g);
}