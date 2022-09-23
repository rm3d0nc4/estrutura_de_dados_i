#include <iostream>
#include <string.h>
#include <string>
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
        else if(ehOperando(infixa[i]) || infixa[i] == '.') posfixa += infixa[i];
        else if(ehOperador(infixa[i])) {
            posfixa += ' ';
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

float calcularValorExpressao(string exp) {
    Pilha<float> pilhaExp(exp.length()); // Pilha de int
    float x, y, result;

    for (int i = 0; i < exp.length(); i++) {
        if(ehOperando(exp[i])) {
            pilhaExp.push(stof(exp.substr(i, exp.length())));
            while (ehOperando(exp[i+1]) || exp[i+1] == '.') {
                i++;
                };
        } else if(ehOperador(exp[i])) {
            y = pilhaExp.pop();
            x = pilhaExp.pop();
            switch (exp[i]){
                case '+': pilhaExp.push(x+y); break;
                case '-': pilhaExp.push(x-y); break;
                case '*': pilhaExp.push(x*y); break;
                case '/': pilhaExp.push(x/y); break;
            }
        }
    }

    result = pilhaExp.pop();
    return result;
}

int main() {
    string infixa = "2*34+1.79/5";

    string posfixa = converterParaPosfixa(infixa);
    cout << posfixa << endl;

    float result = calcularValorExpressao(posfixa);
    cout << "Result: " << result << endl;
}