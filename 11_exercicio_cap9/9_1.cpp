#include <iostream>
#include "lista.hpp" // Lista de int;


using namespace std;

int main() {
    Lista lista = no(3, no(1, no(5, NULL)));
    exibirInvertido(lista);

    return 0;
}