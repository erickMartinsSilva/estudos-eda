// Função que retira elementos de uma lista simplesmente encadeada
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

noPtr topo = NULL;

bool listaVazia() {
    if(topo) {
        return false;
    }
    else {
        return true;
    }
}

void retira() {
    noPtr aux, ant; int n;
    if(listaVazia()) {
        cout << "Lista vazia!\n";
    }
    else {
        cout << "Insira um numero: ";
        cin >> n;
        aux = topo;
        while(aux != NULL && aux->info != n) {
            ant = aux;
            aux = aux->prox;
        }
        if(aux->info == n) {
            ant->prox = aux->prox;
            delete(aux);
        }
        else {
            cout << "Numero nao encontrado\n";
        }
    }
}