#include "ultils.hpp"
#include "iostream"

using namespace std;

int selection(int vetor[], int tamanho) {
    int posicao = 0;
    for (int i = 1; i < tamanho; i++) {
        if (vetor[posicao] < vetor[i]) {
            posicao = i;
        }
    }
    return posicao;
}

/* void selectionSort(int vetor[], int tamanho) {
    for (int i = tamanho; i > 0; i--) {
        troca(&vetor[selection(vetor, i)], &vetor[i-1]);
    }
} */

void selectionSortRecursivo(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return;
    }

    troca(&vetor[selection(vetor, tamanho)], &vetor[tamanho - 1]);

    selectionSortRecursivo(vetor, tamanho-1);
}

int main() {
    int vetor[] = {46, 18, 35, 9};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    selectionSortRecursivo(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        cout << i << ": " << vetor[i] << endl;
    }
}