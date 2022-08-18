#include <stdio.h>

int main() {
    int h;
    int week, days, hours;

    printf("Total hours: ");
    scanf("%i", &h);

    hours = h % 24;
    days = ((h - hours) / 24) % 7;
    week = (((h - hours) / 24) - days) / 7;

    printf("%i hours is equals to %i weeks, %i days and %i hours", h, week, days, hours);

}