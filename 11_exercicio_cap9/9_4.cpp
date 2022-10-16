#include <iostream>
#include "lista.hpp"

using namespace std;

Lista inversa(Lista lista) {
    if(lista == NULL) return lista;
    
    Lista novaLista = NULL;

    while (lista != NULL) {
        novaLista = no(lista->item, novaLista);
        lista = lista->prox;
    }
    return novaLista;
}


int main() {

    Lista lista = no(1, no(2, no(3, no(4, no(5, NULL)))));
    exibir(lista);
    cout << endl;
    Lista listaInversa = inversa(lista);
    exibir(listaInversa);

}