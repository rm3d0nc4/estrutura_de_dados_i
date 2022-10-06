#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct aluno{
	int matricula;
	string nome;	
}Aluno; 

Aluno lista[30];
int counter = -1;



//retorna a posicao do elemento procurado
int procura(int matricula){	
	for(int i = 0; i <= counter; i++) {
		if (lista[i].matricula == matricula) {
			return i;
		}
	}
	return -1;
}

void incluirDesordenado(Aluno aluno){
	if (procura(aluno.matricula) == -1) {
		counter++;
		lista[counter] = aluno;
	} else {
		cout << "Aluno ja cadastrado!" << endl;
	}
}

//recebe a posicao e imprime o elemento na tela
void mostrar(int posicao){
	cout << "Aluno: " << endl;
	cout << "\tNome: " << lista[posicao].nome << endl;
	cout << "\tMatricula: " << lista[posicao].matricula << endl;
}

//procura o elemento e depois mostra o elemento encontrado (se nao for encontrado informa q ele nao existe)
void consultar(int matricula){
	int posicaoAluno = procura(matricula);
	
	if(posicaoAluno != -1) mostrar(posicaoAluno);
	else cout << "Aluno nao encontrado" << endl;
}

//estrat�gia 1: colocar o ultimo elemento da lista na posi��o do elemento removido
void remover00(int matricula){
	int posicao = procura(matricula);

	lista[posicao] = lista[counter];
	free(&lista[counter]);
	counter--;
}

//estrat�gia 2: mover TODOS os elementos que est�o AP�S  o elemento que deve ser removido UMA POSI��O A FRENTE.
void remover01(int matricula){
	int posicao = procura(matricula);
	
	if (posicao != -1) {
		for(int i = posicao; i <= counter; i++) {
			lista[i] = lista[i+1];
		}
		free(&lista[counter]);
		counter--;
	}
}

void verMatriculas() {
	for( int i = 0; i <= counter; i++) {
		cout << lista[i].matricula << endl;
	}
}

main(){
	Aluno aluno1;
	aluno1.matricula = 1;
	aluno1.nome = "Joao";

	Aluno aluno2;
	aluno2.matricula = 2;
	aluno2.nome = "Jose";

	Aluno aluno3;
	aluno3.matricula = 3;
	aluno3.nome = "Josias";

	Aluno aluno4;
	aluno4.matricula = 4;
	aluno4.nome = "Joana";

	Aluno aluno5;
	aluno5.matricula = 5;
	aluno5.nome = "Joselia";

	Aluno aluno6;
	aluno6.matricula = 6;
	aluno6.nome = "Josiana";

	incluirDesordenado(aluno1);
	incluirDesordenado(aluno2);
	incluirDesordenado(aluno3);
	incluirDesordenado(aluno4);
	incluirDesordenado(aluno5);
	incluirDesordenado(aluno6);

	verMatriculas();
	cout << "=============" << endl;
	remover00(3);
	verMatriculas();
	cout << "=============" << endl;
	remover01(2);
	verMatriculas();
	cout << "=============" << endl;
	mostrar(0);
}