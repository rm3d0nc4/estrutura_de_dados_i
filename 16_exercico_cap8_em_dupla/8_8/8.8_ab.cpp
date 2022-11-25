#include<stdio.h>
#include<iostream>
using namespace std;

#define troca(a, b) {int x = a; a = b; b = x; }

void printVetor(int vetor[], int tamanho) {
	for(int i = 0; i <= tamanho; i++) {
		cout << vetor[i] << ' ';
	}

	cout << endl << "=============================" << endl;
}

int particiona(int v[], int p, int u) {
    int pivo = v[p]; //46
    p--;
    u++;


    while(p < u) { 
        do p++; while (v[p] < pivo);
        do u--; while (v[u] > pivo);
        if(p < u) troca(v[p], v[u]);
    }
    return u;
}

void quick_sort(int v[], int p, int u) {
    if(p >= u) return;
    int m = particiona(v, p, u);
    quick_sort(v, p, m);
    quick_sort(v, m+1, u);
}

int main() {
    int vetor1 [7] = {72, 69, 51, 46, 33, 28, 15};
    quick_sort(vetor1, 0, 6);
    printVetor(vetor1, 6);

    int vetor2 [7] = {46, 28, 51, 33, 72, 15, 69};
    quick_sort(vetor2, 0, 6);
    printVetor(vetor2, 6);
} 