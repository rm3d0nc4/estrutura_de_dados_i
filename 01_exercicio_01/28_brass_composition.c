#include <stdio.h>

int main() {
    float brass_weight;
    float zinc, cooper;

    printf("Brass weight (kg): ");
    scanf("%f", &brass_weight);

    cooper = brass_weight * 0.7;
    zinc = brass_weight * 0.3;

    printf("amount of cooper: %0.2f kg", cooper);
    printf("amount of zinc: %0.2f kg", zinc);
}