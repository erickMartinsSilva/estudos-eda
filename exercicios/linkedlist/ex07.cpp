// Função que insere elementos numa lista simplesmente encadeada em ordem crescente
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
    } else return true;
}

void insere() {
    noPtr aux, ant, p = new no;
    if(listaVazia()) {
        cout << "Lista vazia!\n";
    }
    else {
        cout << "Insira um numero: ";
        cin >> p->info;
        while(aux != NULL && p->info > aux->info) {
            ant = aux;
            aux = aux->prox;
        }
        if(aux == topo) {
            p->prox = topo;
            topo = p;
        }
        else {
            ant->prox = p;
            p->prox = aux;
        }
    }
}