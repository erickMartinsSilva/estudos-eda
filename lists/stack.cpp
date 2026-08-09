// Exemplo de uma lista encadeada com a política de pilha (LIFO)
#include <iostream>

using namespace std;

struct no { // estrutura que representa cada elemento da lista
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
noPtr topo = NULL;

int menu() {
    int op;
    cout << "\n1. Inserir\n2. Remover\n3. Imprimir\n4. Sair\n";
    cin >> op;
    return op;
}

bool listaVazia() {
    if(topo) {
        return false;
    } else return true;
}

void push() {
    noPtr p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p->info;
    p->prox = topo;
    topo = p;
}

void pop() {
    noPtr p = topo;
    if(!listaVazia()) {
        topo = topo->prox;
        delete(p);
        cout << "Elemento retirado da pilha.";
    } else cout << "Lista vazia!";
}

void imprimirLista() {
    noPtr aux = topo;
    if(!listaVazia()) {
        while(aux != NULL) {
            cout << aux->info << " ";
            aux = aux->prox;
        }
    } else cout << "Lista vazia!";
}

int main() {
    int op;
    do {
        op = menu();
        switch(op) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: imprimirLista(); break;
            default: break;
        }
    } while(op != 4);
    return 0;
}