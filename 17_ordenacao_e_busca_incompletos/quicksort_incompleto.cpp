#include<stdio.h>
#include<iostream>
using namespace std;
#define troca(a, b) {int x = a; a = b; b = x; }

int particiona(int vetor[], int inicio, int fim) {
   int x = vetor[inicio]; 
   inicio--; 
   fim++; 

   while(inicio < fim) {
      do fim--; while (vetor[fim] > x);  
      do inicio++; while (vetor[inicio] < x); 
      if(inicio < fim) troca(vetor[inicio], vetor[fim]);
   }
   return fim; 
}

void quickSort(int vetor[], int inicio, int fim) {  
   if(inicio >= fim) return;
   int meio = particiona(vetor, inicio, fim);
   quickSort(vetor, inicio, meio);
   quickSort(vetor, meio + 1, fim);
}

int main(){
   int vetor[6] = {7, 3, 9, 1, 6, 8};

   quickSort(vetor, 0, 5);
   printf("\n2.Vetor ordenado:\n");
   for(int i = 0; i <= 5; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");   
}
