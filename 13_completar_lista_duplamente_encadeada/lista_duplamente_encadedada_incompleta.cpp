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
			
		}
		
		void addToIni(int m, char n[23]){
			
		}
		
		void addOrd(int m, char n[23]){
			
		}
		
		//mostra todos os elementos do inicio ao final da lista
		void mostraIniFim(){
			
		}
		
		// mostra todos os elementos do final ao inicio da lista
		void mostraFimIni(){
			
		}
		
		int removerFinal(){
			
		}
		
		int removerInicio(){
			
		}

		int remover(int m){
			
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
