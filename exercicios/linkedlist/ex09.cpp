// Funções de inserção e remoção de termos com base na política de pilha (last in, first out)
#include <iostream>

using namespace std;

struct ctrlZ {
    int acao;
    struct ctrlZ* prox;
};

typedef struct ctrlZ* ctrlZPtr;

ctrlZPtr topo = NULL;

bool listaVazia() {
    if(topo) {
        return false;
    }
    else {
        return true;
    }
}

void insere() {
    ctrlZPtr p = new ctrlZ;
    cout << "Insira uma acao: ";
    cin >> p->acao;
    p->prox = topo;
    topo = p;
}

void remove() {
    ctrlZPtr aux = topo;
    if(listaVazia()) {
        cout << "Lista vazia!\n";
    }
    else {
        topo = topo->prox;
        delete aux;
    }
}