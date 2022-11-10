#include <iostream>

void insere(int elemento, int vetor [], int posicao) {
    while (posicao > 0 && elemento < vetor[posicao-1]) {
        vetor[posicao] = vetor[posicao-1];
        posicao--;
    }
    vetor[posicao] = elemento;
}

void insertionSort(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        insere(vetor[i], vetor, i);
    }
}