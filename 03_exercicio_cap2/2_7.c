#include <stdio.h>
#include <string.h>
#include "./pilhaS.h" // Pilha de char*


int main() {
    PilhaS pilha = criarPilhaS(5);

    char s[11];

    for (int i = 0; i < 3; i++) {
        printf("? ");
        gets(s);
        pushS(_strdup(s), pilha);
    }

    while (!ehPilhaSVazia(pilha)) {
        puts(popS(pilha));
    }
    
}
