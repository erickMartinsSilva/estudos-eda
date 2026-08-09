// Exemplo do funcionamento de uma lista encadeada com a política de fila (FIFO)
#include <iostream>

using namespace std;

struct no { // estrutura para cada elemento da lista
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
noPtr topo = NULL; // lista inicialmente vazia

int menu() {
    int op; 
    cout << "\n1. Adicionar\n2. Remover\n3. Imprimir lista\n4. Sair\n";
    cin >> op;
    return op;
}

bool listaVazia() {
    if(topo) {
        return false;
    } else return true;
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

void enqueue() { // insere elementos no fim da lista
    noPtr ult, p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p->info;
    p->prox = NULL;
    if(listaVazia()) {
        topo = p; // insere elemento no topo se a lista estiver vazia (topo = último elemento)
        cout << "Elemento adicionado com sucesso!\nNova lista: "; imprimirLista();
    } else {
        ult = topo;
        while(ult->prox != NULL) { // usa um loop while para encontrar o último elemento da lista
            ult = ult->prox;
        }
        ult->prox = p; // o elemento após o último agora é p, o novo último da lista
        cout << "Elemento adicionado com sucesso!\nNova lista: "; imprimirLista();
    }
}

void dequeue() { // remove elementos do topo da lista
    noPtr p = topo;
    if(listaVazia()) {
        cout << "Lista vazia!";
    } else {
        topo = topo->prox; // topo agora aponta para o elemento depois de p, o novo primeiro elemento da lista
        delete(p);
        cout << "Elemento removido com sucesso!\nNova lista: "; imprimirLista();
    }
}

int main() {
    int op;
    do {
        op = menu();
        switch(op) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: imprimirLista(); break;
            default: break;
        }
    } while(op != 4);
    return 0;
}