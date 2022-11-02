#include <stdio.h>
#include <iostream>

using namespace std;

typedef int Item;

typedef struct No {
    Item item;
    struct No *prox;
} *Lista;

Lista no(Item item, No *prox) {
    Lista lista = (Lista)malloc(sizeof(No));

    lista->item = item;
    lista->prox = prox;

    return lista;
}

void exibir(Lista lista) {
    cout << lista->item << " ";
    if(lista->prox != NULL) exibir(lista->prox);
}

void anexar(Lista *lista1, Lista lista2) {
    if(lista2 == NULL) return;
    while ( *lista1 != NULL) lista1 = &(*lista1)->prox;
    *lista1 = lista2;
}

void destruir(Lista *lista) {
    while (*lista != NULL){
        Lista elemento = *lista;
        *lista = elemento->prox;
        free(elemento);
    }
    
}

int pertence(Item item, Lista lista) {
    if(lista == NULL) return 0;
    if(item == lista->item) return 1;
    return pertence(item, lista->prox);
}

Lista clonar(Lista lista) {
    if(lista == NULL) return NULL;
    return no(lista->item, clonar(lista->prox));
}

void exibirInvertido(Lista lista) {
    if(lista == NULL) return;
    exibirInvertido(lista->prox);
    cout << lista->item << " ";
}

/* ============ Métodos de lista ordenada ============ */

void inserir(Item item, Lista *lista) {
    while(*lista != NULL && (*lista)->item < item) lista = &(*lista)->prox;
    *lista = no(item, *lista);  
}

void remover(Item item, Lista *lista) {
    while(*lista != NULL && (*lista)->item < item) lista = &(*lista)->prox;
    if(*lista == NULL || (*lista)->item > item) return;
    Lista no = *lista;
    *lista = no->prox;
    free(no);
}

int estaEm(Item item, Lista lista) {
    while(lista != NULL && lista->item < item) lista = lista->prox;
    return lista != NULL && lista->item == item;
}