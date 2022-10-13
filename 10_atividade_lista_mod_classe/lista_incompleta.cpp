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

		// auxiliar no metodo remove, vai 
		//retornar o endereco do anterior
		No* busca(int matricula) {
			No* elemento = inicio;

			if(matricula != inicio->matricula) {
				while (elemento->prox != NULL && elemento->prox->matricula != matricula) {
					elemento = elemento->prox;
				}

				if(elemento->prox->matricula != matricula) {
					cout << "ERRO: Matricula nao encontrada! -> " << matricula << " -> " << elemento->matricula << endl; 
					system("pause"); 
					// abort();
				} else {
					// cout << "Nome: " << elemento->prox->nome << " - Matricula: " << elemento->prox->matricula << endl;
				}
			}
			return elemento;
		}
		
		int remove(int matricula) { // Com algum problema
			No* elemento = busca(matricula);

			if(elemento->matricula == inicio->matricula && matricula == inicio->matricula) {
				inicio = inicio->prox;
			} else if (elemento->prox->matricula == fim->matricula) {
				fim = elemento;
				elemento->prox = NULL;
			} else {
				// mostra(); OK
				elemento->prox = elemento->prox->prox; // exatamente aqui
				// mostra(); OK
			}	
			
			free(elemento);
			return matricula;
		}
		
		void removeTodos() {
			No *atual = inicio;
			No *proximo = NULL;

			while (atual != NULL) {
					proximo = atual->prox;
					cout<<"Apaga:"<<atual->nome << endl;;
					free(atual);
					atual=proximo;						
			}
			inicio=atual;
		}
		
		// criar uma nova lista que seja o inverso da primeira
		Lista* crialistainversa() {
			Lista* novaLista = new Lista;
			No* elementoAtual = inicio;

			while (elementoAtual->prox != NULL) {
				novaLista->addToFinal(elementoAtual->matricula, elementoAtual->nome);
				elementoAtual = elementoAtual->prox;
			}
			free(elementoAtual);

			return novaLista;
		}
		
		//inverter a propria lista
		void listainvertida() {
			int matriculaInicio = inicio->matricula;
			int matriculaFim = fim->matricula;
			No* elementoARemover = busca(fim->matricula);
			No* elementoAnterior = busca(elementoARemover->matricula);

			while (elementoARemover->matricula != matriculaInicio) {
				addToFinal(elementoARemover->matricula, elementoARemover->nome);
				// remove(elementoARemover->matricula);
				
				// cout << "R: " << elementoARemover->matricula << endl;
				// cout << "A: " << elementoAnterior->matricula << endl;

				elementoARemover = elementoAnterior;
				elementoAnterior = busca(elementoARemover->matricula);
				
				// cout << elementoARemover->matricula << matriculaInicio << endl;
			};

			addToFinal(inicio->matricula, inicio->nome);
			remove(inicio->matricula);
			while (inicio->matricula != matriculaFim) {
				inicio = inicio->prox;
			}
			

			free(elementoARemover);
			free(elementoAnterior);
			free(&matriculaInicio);
			free(&matriculaFim);
		}
};

main() {
	Lista* lista = new Lista();
	lista->addToFinal(1,"Joao");
	lista->addToFinal(2,"Gabriela");
	lista->addToFinal(3,"Fabiola");
	lista->addToInicio(5,"Joana Oliveira");
	lista->addToInicio(6,"Cristiano Oliveira");	
	lista->mostra();
	lista->listainvertida();
	// lista->remove(1);
	lista->mostra();
	// cout << "Certo!" << endl;
}
