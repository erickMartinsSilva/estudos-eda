// Função que percorre uma lista simplesmente encadeada e retorna seu tamanho (número de elementos)
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

noPtr topo = NULL;

int sizeList() {
    noPtr aux = topo; int cntd = 0;
    while(aux != NULL) {
        cntd++;
        aux = aux->prox;
    }
    return cntd;
}