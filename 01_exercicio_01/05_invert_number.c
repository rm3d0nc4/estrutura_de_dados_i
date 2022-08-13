#include <stdio.h>
#include <math.h>

int main() {
    int num;

    printf("Int number (3 digits): ");
    scanf("%i", &num);

    printf("%i", num % 10);
    printf("%i", (num % 100 - num % 10) / 10);
    printf("%i", (num - (num % 100)) / 100);

}