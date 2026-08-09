// Função que percorre uma lista simplesmente encadeada e retorna quantos elementos são maiores que um N informado pelo usuário
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

noPtr topo = NULL;

int listaNumerosMaiorQueN() {
    noPtr aux = topo; int cntd = 0, n;
    cout << "Insira um numero: ";
    cin >> n;
    while(aux != NULL) {
        if(aux->info > n) {
            cntd++;
        }
        aux = aux->prox;
    }
    return cntd;
}