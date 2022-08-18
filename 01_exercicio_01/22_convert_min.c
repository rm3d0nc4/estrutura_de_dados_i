#include <stdio.h>

int main() {
    int min;
    int days, hours, minutes;

    printf("Total minutes: ");
    scanf("%i", &min);

    minutes = min % 60;
    hours = ((min - minutes) / 60) % 24;
    days = (((min - minutes) / 60) - hours) / 24;

    printf("%i minutes is equals to %i days, %i hours and %i minutes", min, days, hours , minutes);

}