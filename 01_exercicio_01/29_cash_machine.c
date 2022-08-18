#include <stdio.h>

int main() {
    int amount;
    int notes_of_50, notes_of_20, notes_of_10; 
    int notes_of_5, notes_of_2;

    printf("R$ amount:");
    scanf("%i", &amount);

    notes_of_50 = (amount - (amount % 50)) / 50;
    amount -= notes_of_50 * 50;

    notes_of_20 = (amount - (amount % 20)) / 20;
    amount -= notes_of_20 * 20;

    notes_of_10 = (amount - (amount % 10)) / 10;
    amount -= notes_of_10 * 10;

    notes_of_5 = (amount - (amount % 5)) / 5;
    amount -= notes_of_5 * 5;

    notes_of_2 = amount / 2;

    printf("Distribution of notes:");
    printf("\n  notes of 50: %i", notes_of_50);
    printf("\n  notes of 20: %i", notes_of_20);
    printf("\n  notes of 10: %i", notes_of_10);
    printf("\n  notes of 5: %i", notes_of_5);
    printf("\n  notes of 2: %i", notes_of_2);

}