#include <stdio.h>
#include <stdlib.h>

typedef char ItemPilha;

typedef struct pilha {
    int max;  // Capacidade da pilha
    int topo; // Posição do topo
    ItemPilha *item; // Itens da pilha
} *Pilha;

Pilha criarPilha(int tamanho) {
    Pilha pilha = malloc(sizeof(struct pilha)); // Aloca área na memória

    pilha->max = tamanho; // indica capacidade de itens da pilha
    pilha->topo = -1; // Indica que a pilha está (inicialmente) vazia
    pilha->item = malloc(sizeof(ItemPilha));

    return pilha;
}

int ehPilhaVazia(Pilha pilha) {
    return pilha->topo == -1;
}

int ehPilhaCheia(Pilha pilha) {
    return pilha->topo == pilha->max-1;
}

void empilhar(ItemPilha itemp, Pilha pilha) {

    if( !ehPilhaCheia(pilha)) {

        pilha->topo++;
        pilha->item[pilha->topo] = itemp;
    } else {
        printf("Pilha cheia!");
        abort();
    }

}

void destruirPilha(Pilha *ponteiroPilha) {
    
    free((*ponteiroPilha)->item);
    free(*ponteiroPilha);
    *ponteiroPilha = NULL;
}

ItemPilha desempilhar(Pilha pilha) {
    
    if( ehPilhaVazia(pilha)) { puts("A pilha está vazia!"); abort(); }
    
    ItemPilha item = pilha->item[pilha->topo];
    pilha->topo--;

    return item;
}

ItemPilha getTopo(Pilha pilha) {

    if( ehPilhaVazia(pilha)) { puts("A pilha está vazia!"); abort(); }
    return pilha->item[pilha->topo];

}

int main() {
    Pilha pilha1 = criarPilha(3);


    printf("Tamanho: %i\n", pilha1->max);
    printf("Item: %i\n", pilha1->item);
    printf("Topo: %i\n", pilha1->topo);

    printf("Vazia: %i\n", ehPilhaVazia(pilha1));
    printf("Cheia: %i\n", ehPilhaCheia(pilha1));

    empilhar('o', pilha1);
    empilhar('r', pilha1);
    empilhar('e', pilha1);
    // empilhar('e', pilha1);

    printf("Empilhou\n");

    printf("Vazia: %i\n", ehPilhaVazia(pilha1));
    printf("Cheia: %i\n", ehPilhaCheia(pilha1));

    desempilhar(pilha1);
    desempilhar(pilha1);
    desempilhar(pilha1);
    // desempilhar(pilha1);

    printf("Desempilhou\n");

    printf("Vazia: %i\n", ehPilhaVazia(pilha1));
    printf("Cheia: %i\n", ehPilhaCheia(pilha1));
}
