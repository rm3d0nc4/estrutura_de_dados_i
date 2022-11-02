#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No{
	public:
		int mat;
		char nome[23];
		No *prox;
		No *ant;
		No(int m,char n[23]){
			mat=m;
			strcpy(nome,n);
			prox=NULL;
			ant=NULL;
		}
};

class Lista{
	public:
		No *inicio;
		No *fim;
	
		Lista(){
			inicio = NULL;
			fim = NULL;
		}	

		void addToFinal(int m, char n[23]){
			No* novoNo = new No(m, n);
			
			if(fim == NULL) {
				fim = novoNo;
				inicio = novoNo;
			} else {
				fim->prox = novoNo;
				novoNo->ant = fim;
				fim = novoNo;
			}
		}
		
		void addToIni(int m, char n[23]){
			No* novoNo = new No(m, n);

			if(inicio == NULL) {
				fim = novoNo;
				inicio = novoNo;
			} else {
				inicio->ant = novoNo;
				novoNo->prox = inicio;
				inicio = novoNo;

			}
		}
		
		void addOrd(int m, char n[23]){
			No* novoNo = new No(m, n);
			
			if(inicio == NULL) {
				inicio = novoNo;
				fim = novoNo;

			} else if(inicio == fim) {
				if(m > inicio->mat) {
					addToFinal(m, n);
				} else {
					addToIni(m,n);
				}
				free(novoNo);
			} else {
				No* atual = inicio;
				while(atual->mat < m && atual->prox != NULL) {
					atual = atual->prox;
				}
				novoNo->prox = atual;
				novoNo->ant = atual->ant;
				atual->ant->prox = novoNo;
				atual->ant = novoNo;

				atual = novoNo;
			}
			return;
		}
		
		//mostra todos os elementos do inicio ao final da lista
		void mostraIniFim(){
			if (inicio == NULL) cout<<"\nLista vazia!!!";
			else {
				No* elemento = inicio;
				while (elemento != NULL) {
					cout << elemento->mat << ": " << elemento->nome << endl;
					elemento = elemento->prox;
				}
				free(elemento);
				cout << endl;
			}
		}
		
		// mostra todos os elementos do final ao inicio da lista
		void mostraFimIni(){
			if (fim == NULL) cout<<"\nLista vazia!!!";
			else {
				No* elemento = fim;
				while (elemento != NULL) {
					cout << elemento->mat << ": " << elemento->nome << endl;
					elemento = elemento->ant;
				}
				free(elemento);
				cout << endl;
			}
		}
		
		int removerFinal(){
			No* elemento = fim;
			fim = fim->ant;
			free(elemento);
			return elemento->mat;
		}
		
		int removerInicio(){
			No* elemento = inicio;
			inicio = inicio->prox;
			free(elemento);
			return elemento->mat;
		}

		int remover(int m){
			if(m == inicio->mat) {
				removerInicio();
			} else if(m == fim->mat) {
				removerFinal();
			} else {
				No* atual = inicio->prox;

				while(atual->mat != m) {
					if(atual->mat > m || atual == NULL) return 0;
					else atual = atual->prox;
				}
				
				atual->ant->prox = atual->prox;
				atual->prox->ant = atual->ant;
				free(atual);
			}
			return 1;
		}
};
main(){
	Lista *l=new Lista();
	
	l->addOrd(1,"Joana Oliveira");
	l->addOrd(10,"Cristiano Oliveira");
	// l->mostra();
	l->addOrd(8,"Joao");
	l->addOrd(4,"Fabio");
	l->mostraIniFim(); 
	// l->mostraFimIni();	
	if (l->remover(4)==1)
		cout<<"Elemento removido!!"<<endl;
	else
		cout<<"Elemento nao encontrado!!"<<endl;    
	l->mostraIniFim(); 
}
