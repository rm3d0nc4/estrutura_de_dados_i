#include <stdio.h>

int main() {
    float cm, m, km;

    printf("cm value: ");
    scanf("%f", &cm);

    m = cm / 100;
    km = m / 1000;

    printf("%0.2f centimetters is equals to metters %0.2f ", cm, m);
    printf("\n%0.2f centimetters is equals to %0.2f kilometer", cm, km);
}