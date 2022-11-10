#include <iostream>

#define troca(a, b) {int x = a; a = b; b = x; }

int seleciona(int vetor[], int n) {
    int i = 0;
    for(int j = i; j < n; j++) {
        if(vetor[i] < vetor[j]) i = j;
    }
    return i;
}

void selectionSort(int vetor[], int n) {
    while(n > 1) {
        troca(vetor[seleciona(vetor, n)], vetor[n-1]);
    }
}