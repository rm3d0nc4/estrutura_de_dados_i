#include <stdio.h>
#include <math.h>

int main() {
    float purchase_value;
    float input_value, installment_value;

    printf("Purchase value:");
    scanf("%f", &purchase_value);

    installment_value = trunc(purchase_value/3);
    input_value = installment_value + (purchase_value / 3 - installment_value);

    printf("Input value: %0.2f", input_value);
    printf("\nInstallment value: %0.2f", installment_value);
}