#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

// void f1(char hello[]) {
//     printf("From f1: %d\n", &hello);
//     printf("From f1: %d\n", &hello[0]);
//     printf("From f1: %d\n", &hello[1]);
//     printf("From f1: %d\n", &hello[2]);

// }

// void main() {
//     char hello[] = "Hello World";
//     printf("From main: %d\n", &hello);
//     printf("From main: %d\n", &hello[0]);
//     printf("From main: %d\n", &hello[1]);
//     printf("From main: %d\n", &hello[2]);
//     f1(hello);

//     return;
// }

struct  Person{
    char nome[10];
    uint8_t age; // Inteiros de 8 bits sem sinal (idades de 0 a 255);
    uint8_t height;
};

void main() {
    struct Person person;

    strcpy(person.nome, "Romero");
    person.age = 18;
    person.height = 185;
}
