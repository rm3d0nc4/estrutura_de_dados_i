#include <iostream>
#define troca(a, b) {int x = a; a = b; b = x; }

void bubbleSort(int vetor[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i; j++) {
            if(vetor[j] > vetor[j+1]) {
                troca(vetor[j], vetor[j+1]);
            }
        } 
    }
}