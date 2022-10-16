#include <iostream>

#include "lista.hpp"

using namespace std;

void enfileirar(Item item, Lista *fila) {
    while (*fila != NULL) fila = &(*fila)->prox;
    *fila = no(item, NULL);
}

Item desenfileirar(Lista *fila) {
    Item item = (*fila)->item;
    *fila = (*fila)->prox;
    return item;
}

int main() {
    Lista fila = no(1, no(2, no(3, no(4, no(5, NULL)))));

    enfileirar(6, &fila);
    exibir(fila);
    
    cout << endl;

    desenfileirar(&fila);
    exibir(fila);
}