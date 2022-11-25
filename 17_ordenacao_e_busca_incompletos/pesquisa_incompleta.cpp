#include<stdio.h>
#include<iostream>
#include <string.h>

using namespace std;

int pesquisa_linear(int x,int v[], int n) {
   for(int i = 0; i < n; i++ ) {
      if(v[i] == x) return 1;
   }
   return 0;
}
int pesquisa_binaria(int x,int v[], int n) {
   int inicio = 0;
   int fim = n - 1;

   while (inicio <= fim) {
      int meio = (inicio + fim) / 2;
      if(x == v[meio]) return 1;
      if( x < v[meio]) fim = meio - 1;
      else inicio = meio + 1;
   }
   return 0;
}

int main() {
   int vetor[] = {1,2,3,4,5,6,7,8,9};
   int itemExiste = pesquisa_binaria(1, vetor, 9);
   cout << itemExiste << endl;
}


