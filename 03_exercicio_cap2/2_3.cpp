#include <iostream>
#include <cstring>
#include "./pilhaS.h" // pilha de char

using namespace std;


int main() {
    char frase[500];

    
    printf("Frase: ");
    scanf("%[^\n]", &frase);
    
    PilhaS pilha = criarPilhaS(strlen(frase));


    for (int i = 0; i < strlen(frase)+1; i++) {
        if(frase[i] != ' ' && frase[i] != '\0') {
            pushS(frase[i], pilha);
        } else {
            while (!ehPilhaSVazia(pilha)) {
                cout << popS(pilha);
            }
            cout << " ";
        }
    }    
            cout << endl;
            system("pause");
    

    
}