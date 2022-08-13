#include <stdio.h>

int main() {
    float km, m;

    printf("km value: ");
    scanf("%f", &km);

    m = km * 1000;

    printf("%0.2f km is equals to %0.2f metters", km, m);
}