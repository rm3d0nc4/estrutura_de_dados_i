#include <iostream>

#include "lista.hpp"

using namespace std;

void empilhar(Item item, Lista *topoPilha) {
    *topoPilha = no(item, *topoPilha);
}

Item desempilhar(Lista *pilha) {
    Item item = (*pilha)->item;
    *pilha = (*pilha)->prox;

    return item;
}

int main() {
    Lista pilha = no(1, no(2, no(3, no(4, no(5, NULL)))));

    empilhar(6, &pilha);
    exibir(pilha);
    
    cout << endl;
    
    desempilhar(&pilha);
    desempilhar(&pilha);
    exibir(pilha);
}