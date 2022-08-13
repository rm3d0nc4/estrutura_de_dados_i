#include <stdio.h>

int main() {
    float num;
    float percent_num;

    printf("Number: ");
    scanf("%f", &num);

    percent_num = num * .7;

    printf("70 percent of %0.2f is: %0.2f", num, percent_num);
}