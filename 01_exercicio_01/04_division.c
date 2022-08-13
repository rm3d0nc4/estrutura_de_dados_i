#include <stdio.h>

int main() {
    int n1, n2;
    float division, quotient;

    printf("N1: ");
    scanf("%i", &n1);

    printf("N2: ");
    scanf("%i", &n2);

    division = n1 / n2;
    quotient = n1 % n2;

    printf("Division: %0.2f", division);
    printf("\nQuotient: %0.2f", quotient);
}