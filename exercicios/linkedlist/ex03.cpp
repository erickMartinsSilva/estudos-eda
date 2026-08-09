// Função que recebe o endereço do topo de duas listas simplesmente encadeadas e concatena elas, imprimindo o resultado
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

void concatenarListas(noPtr topo1, noPtr topo2) {
    noPtr ult1, aux;
    ult1 = topo1;
    while(ult1 != NULL) {
        ult1 = ult1->prox;
    }
    ult1->prox = topo2;
    aux = topo1;
    while(aux != NULL) {
        cout << aux->info;
        aux = aux->prox;
    }
}