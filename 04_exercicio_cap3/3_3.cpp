#include <iostream>
#include "pilha.hpp"

using namespace std;

bool ehOperador(char item) {
    return item == '*' || item == '/' || item =='+' || item == '-';
}

bool ehOperando(char item) {
    return !ehOperador(item) && item != '(' && item != ')' && item != ' ';
}

int prioridade(char item) {
    if(item =='(') return 0;
    else if(item == '+' || item == '-') return 1;
    else return 2;
}

string converterParaPosfixa(string infixa) {
    string posfixa = "";
    Pilha<char> pilhasOp(infixa.length()); // Pilha de char

    for (int i = 0; i < infixa.length(); i++) {
        if(infixa[i] == '(') pilhasOp.push('(');
        else if(isalpha(infixa[i])) posfixa += infixa[i];
        else if(ehOperador(infixa[i])) {
            while (!pilhasOp.vazia() && (prioridade(pilhasOp.getTopo()) >= prioridade(infixa[i]))){
                posfixa += pilhasOp.pop();
            }
            
            pilhasOp.push(infixa[i]);
        } else {
            while (pilhasOp.getTopo() != '(') {
                posfixa += pilhasOp.pop();
            }
            pilhasOp.pop();
        }
    }

    while (!pilhasOp.vazia()) {
        posfixa += pilhasOp.pop();
    }
        

    return posfixa;
}

int main() {
    string infixa = "A*B+C/D";

    string posfixa = converterParaPosfixa(infixa);

    cout << posfixa << endl;

}