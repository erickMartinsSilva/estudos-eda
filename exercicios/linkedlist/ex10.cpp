// Função que percorre uma lista simplesmente encadeada, encontra o maior elemento e troca ele de posição com o primeiro
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

void troca() {
    noPtr aux, aux2, maior;
    if(listaVazia()) {
        cout << "Lista vazia!\n";
    } else {
        aux = topo; maior = topo;
        while(aux != NULL) {
            if(maior->info < aux->info) {
                maior = aux;
            }
            aux = aux->prox;
        }
        aux2 = maior;
        maior = topo;
        topo = aux2;
    }
}

// Complexidade de pior caso: O(n), pois precisamos percorrer a lista inteira para determinar o maior elemento