// Função que recebe uma lista simplesmente encadeada e um numero n como parâmetros e divide a lista em duas se o elemento existir na
// lista, onde o primeiro elemento da segunda lista será o elemento n
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

void divide(noPtr topo, int n) {
    noPtr aux, ant, topo2;
    aux = topo;
    while(aux != NULL && aux->info != n) {
        ant = aux;
        aux = aux->prox;
    }
    if(aux->info == n) {
        topo2 = aux;
        ant->prox = NULL;
    }
    else {
        cout << "Numero nao encontrado\n";
    }
}