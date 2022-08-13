#include <stdio.h>

int main() {
    float usd_quote;
    float usd_value;
    float brl_value;

    printf("USD quote in BRL: ");
    scanf("%f", &usd_quote);

    printf("USD value: ");
    scanf("%f", &usd_value);

    brl_value = usd_quote * usd_value;

    printf("BRL value: %0.2f", brl_value);


}