#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class No {
	public:
		int matricula;
		char nome[23];
		No *prox;
		
		No(int mat ,char name[23]) {
			matricula = mat;
			strcpy(nome,name); //  copia o valor da string na segunda posição do argumento para uma variável string na primeira posição
			prox = NULL;
		}
};

class Lista {
	public:
		No *inicio;
		No *fim;
	
		Lista() {
			inicio = NULL;
			fim = NULL;
		}
			
		void addToFinal(int matricula, char nome[23]) {
			No* novo = new No(matricula, nome);
			
			if (fim == NULL) {
				inicio = novo;
				fim = novo;
			}
			else {
				fim->prox = novo;
				fim = novo;
			}
		}
			
		int lstVazia() {
			return (inicio == NULL);
		}

		void addToInicio(int matricula,char nome[23]) {
			No* novo = new No(matricula, nome);
			novo->prox = inicio;
			inicio = novo;
		}

		void mostra() {
			if (lstVazia()) cout<<"\nLista vazia!!!";
			else {
				No* elemento = inicio;
				while (elemento != NULL) {
					cout << elemento->matricula << " -> ";
					elemento = elemento->prox;
				}

				cout << endl;
				free(elemento);
			}
		}

		No* busca(int matricula) { 
			No* noAtual = inicio;
			No* procurado = NULL;
			while (noAtual != NULL){
				if(noAtual->matricula == matricula) {
					procurado = noAtual;
					break;
				} else {
					noAtual = noAtual->prox;
				}
			}

			free(noAtual);
			return procurado;
		}
		
		void remove(int matricula) { // Com algum problema
			No* elemento = busca(matricula);
			No* elementoAtual = inicio;

			if(elemento == inicio) {
				inicio = inicio->prox;
			} else {
				while (elementoAtual->prox != elemento) {
					elementoAtual = elementoAtual->prox;
				}
				
				if(elemento == fim) fim = elementoAtual;
				else elementoAtual->prox = elemento->prox;
			}
			free(elemento);
		}
		
		void removeTodos() {
			No *atual = inicio;
			No *proximo = NULL;

			while (atual != NULL) {
					proximo = atual->prox;
					cout<<"Apaga: "<<atual->nome << endl;;
					free(atual);
					atual=proximo;						
			}
			inicio=atual;
		}
		
		// criar uma nova lista que seja o inverso da primeira
		Lista* criaListaInversa() {
			Lista* novaLista = new Lista;
			No* elementoAtual = inicio;

			while (elementoAtual != NULL) {
				novaLista->addToInicio(elementoAtual->matricula, elementoAtual->nome);
				elementoAtual = elementoAtual->prox;
			}
			return novaLista;
		}
		
		//inverter a propria lista
		void listaInvertida() {
			No* elemento = inicio;
			No* atual = elemento->prox;

			while (atual != NULL){
				addToInicio(atual->matricula, atual->nome);
				atual = atual->prox;
			}

			atual = elemento->prox;
			elemento->prox = NULL;

			while (atual != NULL) {
				elemento = atual;
				atual = atual->prox;
				free(elemento);
			}
		}
};

main() {
	Lista* lista = new Lista();
	lista->addToFinal(1,"Joao");
	lista->addToFinal(2,"Gabriela");
	lista->addToFinal(3,"Fabiola");
	lista->addToInicio(5,"Joana Oliveira");
	lista->addToInicio(6,"Cristiano Oliveira");	
	lista->mostra(); // Lista
	lista->listaInvertida();
	lista->mostra(); // Lista Invertida
	lista->remove(1);
	lista->mostra(); //Lista sem o elemento removido

	Lista* lista2 = lista->criaListaInversa();
	lista2->mostra(); // Nova lista invertida
}