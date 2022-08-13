#include <stdio.h>

int main() {
    float m, cm;

    printf("m value: ");
    scanf("%f", &m);

    cm = m * 100;

    printf("%0.2f metters is equals to %0.2f centimetters", m, cm);
}