#include <stdio.h>

int main() {
    float n1, n2, n3;
    float mean;

    printf("N1:");
    scanf("%f", &n1);

    printf("N2:");
    scanf("%f", &n2);

    printf("N3:");
    scanf("%f", &n3);

    mean = (n1 + n2 + n3) / 3;

    printf("Mean: %0.2f", mean);

}