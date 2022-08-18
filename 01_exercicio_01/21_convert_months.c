#include <stdio.h>

int main() {
    int m;
    int year, month;

    printf("Total months: ");
    scanf("%i", &m);

    month = m % 12;
    year = (m - month) / 12;

    printf("%i months is equals to %i years and %i months", m, month, year);
}