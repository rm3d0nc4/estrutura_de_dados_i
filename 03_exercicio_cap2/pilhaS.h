#include <stdio.h>
#include <stdlib.h>

typedef char* ItemPilhaS;

typedef struct pilhaS {
    int max;  // Capacidade da pilha
    int topo; // Posição do topo
    ItemPilhaS *item; // Itens da pilha
} *PilhaS;

int ehPilhaSVazia(PilhaS pilha) {
    return pilha->topo == -1;
}

int ehPilhaSCheia(PilhaS pilha) {
    return pilha->topo == pilha->max-1;
}

PilhaS criarPilhaS(int tamanho) {
    PilhaS pilha = (PilhaS)malloc(sizeof(struct pilhaS)); // Aloca área na memória

    pilha->max = tamanho; // indica capacidade de itens da pilha
    pilha->topo = -1; // Indica que a pilha está (inicialmente) vazia
    pilha->item = (ItemPilhaS*)malloc(sizeof(ItemPilhaS) * tamanho);

    return pilha;
}

void pushS(ItemPilhaS itemp, PilhaS pilha) { //gamb (ItemPilhaS itemp)
    
    if( !ehPilhaSCheia(pilha)) {
        pilha->topo++;
        pilha->item[pilha->topo] = itemp; //gamb (itemp)
    }

}

ItemPilhaS popS(PilhaS pilha) {
    
    if( !ehPilhaSVazia(pilha)) {
        ItemPilhaS item = pilha->item[pilha->topo];
        pilha->topo--;
        
        return item;
    }
}

void showPilhaS(PilhaS pilha) {

    while(!ehPilhaSVazia(pilha)) {
        printf("%s", popS(pilha));
        }
        printf("\n");
}

void destruirPilhaS(PilhaS* ponteiroPilha) {
    
    free((*ponteiroPilha)->item);
    free(ponteiroPilha);
    ponteiroPilha = NULL;
}



ItemPilhaS getTopoS(PilhaS pilha) {

    if( ehPilhaSVazia(pilha)) { puts("A pilha está vazia!"); abort(); }
    return pilha->item[pilha->topo];

}
