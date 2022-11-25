#include<stdio.h>
#include<iostream>
using namespace std;

void intercala(int vetor[], int inicio, int meio, int fim) {
   int *vetorAux = (int *)malloc((fim - inicio + 1) * sizeof(int));
   if(vetorAux == NULL) abort();
   int i = inicio, j = meio + 1, k = 0;

   while (i <= meio && j <= fim) {
      if(vetor[i] < vetor[j]) vetorAux[k++] = vetor[i++]; // posiciona os elementos e depois incrementa os valores de j e i
      else vetorAux[k++] = vetor[j++];
   }

   while( i <= meio) vetorAux[k++] = vetor[i++];
   while( j <= fim) vetorAux[k++] = vetor[j++];
   for(k = 0; k <= fim - inicio; k++) {
      vetor[inicio + k] = vetorAux[k];
   }
   free(vetorAux);
};

void merge_sort(int v[],int inicio, int fim) {
   if(inicio == fim) return;
   int meio = (inicio + fim) / 2;
   merge_sort(v, inicio, meio);
   merge_sort(v, meio + 1, fim);
   intercala(v, inicio, meio, fim);
}



int main(){
   int vetor[6] = {7, 9, 4, 3,6,1};
   merge_sort(vetor, 0 ,5);

   for(int i = 0; i < 6; i++) {
      cout << vetor[i] << " ";
   }
}


