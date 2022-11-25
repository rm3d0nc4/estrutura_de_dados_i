#include <iostream>

using namespace std;

void insere(int elemento, int vetor [], int posicao) {
    while (posicao > 0 && elemento < vetor[posicao-1]) {
        vetor[posicao] = vetor[posicao-1];
        posicao--;
    }
    vetor[posicao] = elemento;
}

void insertionSort(int vetor[], int tamanho) {
    if(tamanho == 1) return;
    insertionSort(vetor, tamanho - 1);
    insere(vetor[tamanho - 1], vetor, tamanho - 1);
    
}

int main() {
    int vetor[5] = {3,4,1,5,2};
    insertionSort(vetor, 5);
    
    for (int i = 0; i < 5; i++){
        cout << vetor[i] << endl;
    }
    

}