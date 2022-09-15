#include <stdio.h>
#include "./pilhaS.h" // Pilha de float

int main() {
    int tam;
    float item;
    float aux;

    printf("Qtd de numeros: ");
    scanf("%d", &tam);

    PilhaS pilhaB = criarPilhaS(tam);
    PilhaS pilhaA = criarPilhaS(tam);

    printf("Itens: ");
    for(int i = 0; i < tam; i++) {
        scanf("%f", &item);
        pushS(item, pilhaB);
    }

    printf("Tranquilo \n");
    while(!ehPilhaSVazia(pilhaB)) {
        if (ehPilhaSVazia(pilhaA) || pilhaA->item[pilhaA->topo] >= pilhaB->item[pilhaB->topo]) {
            pushS(popS(pilhaB), pilhaA);
        } else {
            aux = popS(pilhaB);
            printf("aux: %.2f\n", aux);

            while (!ehPilhaSVazia(pilhaA) && pilhaA->item[pilhaA->topo] < aux) {
                pushS(popS(pilhaA), pilhaB);
            }
            pushS(aux, pilhaA);
            
        }
        
    }

    showPilhaS(pilhaA);

    system("pause");
}


