// Função que recebe uma lista encadeada e um número como parâmetros e remove todas as incidências do número da lista, imprimindo-a
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

void removeFromLista(noPtr topo, int n) {
    noPtr aux, ant, aux2;
    aux = topo;
    while(aux != NULL) {
        ant = aux;
        if(aux->info == n) {
            aux2 = aux;
            ant->prox = aux2->prox;
            delete(aux2);
        }
        aux = aux->prox;
    }
    aux = topo;
    while(aux != NULL) {
        cout << aux->info;
        aux = aux->prox;
    }
}