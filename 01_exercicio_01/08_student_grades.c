#include <stdio.h>

int main() {
    float n1, n2, n3;
    float p1, p2, p3;
    float mean;

    printf("N1 and P1: ");
    scanf("%f %f", &n1, &p1);

    printf("N2 and P2: ");
    scanf("%f %f", &n2, &p2);

    printf("N3 and P3: ");
    scanf("%f %f", &n3, &p3);

    mean = (p1 * n1 + p2 * n2 +  p3 * n3) / (p1 + p2 + p3);

    printf("Mean: %0.2f", mean);


}