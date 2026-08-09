#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
    struct no* ant;
};

typedef struct no* noPtr;

noPtr topo = NULL, ult = NULL;

int menu() {
    int op;
    cout << "\n1. Inserir\n2. Remover\n3. Imprimir Lista\n";
    cin >> op;
    return op;
}

bool listaVazia() {
    if(topo) {
        return true;
    } else return false;
}

void inserir() {
    noPtr p = new no, aux;
    cin >> p->info;
    if(listaVazia()) {
        topo = p;
        ult = topo;
        p->prox = NULL;
    } else {
        aux = topo;
        while(aux != NULL && p->info < aux->info) {
            aux = aux->prox;
        }
        if(aux == topo) {
            p->prox = aux;
            topo = p;
        } else {
            p->ant = aux->ant;
            p->prox = aux;
        }
    }
}

void remover() {
    noPtr aux; int n;
    cin >> n;
    if(listaVazia()) {
        cout << "Lista vazia!\n";
    } else {
        aux = topo;
        while(aux != NULL && aux->info != n) {
            aux = aux->prox;
        }
        if(aux->info == n) {
            if(aux == topo) {
                topo = topo->prox;
                topo->ant = NULL;
                delete aux;
            } else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                delete aux;
            }
        } else {
            cout << "Numero nao encontrado\n";
        }
    }
}

void imprimirLista() {
    if(listaVazia()) {
        cout << "Lista vazia!\n";
    } else {
        noPtr aux = topo;
        while(aux != NULL) {
            cout << aux->info << "\t";
            aux = aux->prox;
        }
    }
}

int main() {
    int op;
    do {
        switch(op = menu()) {
            case 1: inserir(); break;
            case 2: remover(); break;
            case 3: imprimirLista(); break;
            default: break;
        } 
    } while(op != 4);
    return 0;
}