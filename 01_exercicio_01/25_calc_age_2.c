#include <stdio.h>

int main() {
    int d;
    int year, month, day;

    printf("Total age in days: ");
    scanf("%i", &d);
    
    day = d % 30;
    month = ((d - day) / 30) % 12;
    year = (((d - day) / 30) - month) / 12;

    printf("Your age is: %i years, %i months and %i days", year, month, day);
}