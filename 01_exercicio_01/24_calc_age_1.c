#include <stdio.h>

int main() {
    int year, month, day;
    int total_days;

    printf("Input your age: ");

    printf("\n    Year:");
    scanf("%i", &year);
    printf("    Month:");
    scanf("%i", &month);
    printf("    Day:");
    scanf("%i", &day);

    total_days = ((year * 12) + month) * 30 + day;

    printf("Total days: %i", total_days);

    
}