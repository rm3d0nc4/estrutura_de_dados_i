#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

typedef struct aluno {
	int matricula;
	char nome[20];
}Aluno;



void ord_insercao(Aluno vetor[],int tam) {
	for(int i = 0; i < tam; i++) {
		Aluno aux = vetor[i];  
		while (i > 0 &&  aux.matricula < vetor[i - 1].matricula) {
			vetor[i] = vetor[i - 1];
			i--;
		}
		vetor[i] = aux;
    }
};

void selection_sort(Aluno vetor[],int n) {
	while(n > 1) {
		int indice = 0;
		for(int j = indice; j < n; j++) {
			if(strcmp(vetor[indice].nome, vetor[j].nome) == -1) indice = j;
		}

		Aluno aux = vetor[indice];
		vetor[indice] = vetor[n - 1];
		vetor[n-1] = aux;
		n--;
    }
};

void bubble_sort(Aluno vetor[],int n) {
	for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(vetor[j].matricula > vetor[j + 1].matricula) {
				Aluno aux = vetor[j]; 
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
            }
        } 
    }
};

void printVetor(Aluno vetor[], int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		cout << vetor[i].nome << ": " << vetor[i].matricula << endl;
	}
	cout << "=============================" << endl;
}


Aluno myarray[3];
int tamanho = sizeof(myarray) / sizeof(Aluno);

main(){

	for(int i = 0; i < tamanho; i++) {
		Aluno aluno;
		cout << "Nome aluno " << i << ": ";
		cin >> aluno.nome;
		cout << "Matricula aluno " << i << ": ";
		cin >> aluno.matricula;
		myarray[i] = aluno;
	}

	cout << "----------------------------" << endl;

	ord_insercao(myarray, tamanho);
	printVetor(myarray, tamanho);

	selection_sort(myarray, tamanho);
	printVetor(myarray, tamanho);

	bubble_sort(myarray, tamanho);
	printVetor(myarray, tamanho);

}