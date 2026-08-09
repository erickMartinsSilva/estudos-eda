// Exemplo do funcionamento de uma lista encadeada ordenada
#include <iostream>

using namespace std;

struct no { // declaração de uma estrutura que representa cada elemento da lista encadeada
    int info; // valor do elemento
    struct no* prox; // ponteiro que aponta para o endereço do próximo elemento da lista
};

typedef struct no* noPtr;

noPtr topo = NULL; // como topo aponta para NULL, a lista inicialmente está vazia

int menu() {
    int op;
    cout << "\n1. Inserir\n2. Remover\n3. Consultar\n4. Listar em ordem crescente\n5. Listar em ordem decrescente\n6. Sair\n";
    cin >> op;
    return op;
}

bool listaVazia(noPtr topo_lista) {
    if(topo_lista == NULL) {
        return true;
    } else return false;
}

void imprimirLista(noPtr topo_lista) {
    noPtr aux = topo_lista;
    if(!listaVazia(topo_lista)) {
        while(aux != NULL) {
            cout << aux->info << " ";
            aux = aux->prox;
        }
    } else cout << "Lista vazia!";
}

void inserir() {
    noPtr aux, ant, p = new no;
    cout << "Entre com o numero a ser inserido na lista: ";
    cin >> p->info;
    if(listaVazia(topo)) { // se a lista estiver vazia, p será o primeiro elemento da lista
        topo = p;
        p->prox = NULL;
        cout << "Elemento adicionado com sucesso!\nNova lista: "; imprimirLista(topo);
    } else { // se não, como a lista é ordenada, precisamos definir onde p precisa estar
        aux = topo;
        while(aux != NULL && p->info > aux->info) { // confere se p é maior que todos os elementos ou se ele está entre dois elementos na lista
            ant = aux;
            aux = aux->prox;
        }
        if(aux == topo) { // se aux for igual a topo, significa que nada do while foi feito, logo p é menor que todos os elementos da lista
            p->prox = aux; // p aponta para o elemento que era o topo da lista
            topo = p; // topo aponta para p, logo p é o novo primeiro elemento da lista
        } else {
            p->prox = aux; // o próximo elemento de p será o elemento na variável aux. se aux = NULL, p será o último elemento da lista
            ant->prox = p; // se p estiver entre dois elementos, o próximo elemento de p será aux e o próximo elemento do anterior será p
        }
        cout << "Elemento adicionado com sucesso!\nNova lista: "; imprimirLista(topo);
    }
}

void retirar() { // como esta lista não tem uma política pré-definida, podemos remover qualquer elemento
    noPtr aux, ant; int num;
    cout << "Insira um numero: ";
    cin >> num;
    if(listaVazia(topo)) {
        cout << "Lista vazia!";
    } else {
        aux = topo;
        while(aux != NULL && aux->info != num) { // passa por cada elemento da lista até encontrar o número desejado ou até chegar ao fim
            ant = aux;
            aux = aux->prox;
        }
        if(aux->info == num) {
            if(aux == topo) { 
                topo = topo->prox; // se ele estiver no topo, o topo passa a apontar pro elemento posterior ao número
                delete(aux); // número removido
            } else {
                ant->prox = aux->prox; // se ele estiver no fim ou entre dois números, o número anterior aponta para o próximo
                delete(aux); // número removido
            }
            cout << "Elemento removido com sucesso!\nNova lista: "; imprimirLista(topo);
        } else cout << "Numero nao encontrado\n";
    }
}

void consultar() {
    int num, cntd = 1; noPtr aux; bool achei = false;
    if(listaVazia(topo)) {
        cout << "Lista vazia!\n";
    } else {
        cout << "Insira um numero: ";
        cin >> num;
        aux = topo;
        while(aux != NULL && !achei) { // percorre a lista encadeada até chegar no fim ou até o número ser encontrado
            if(aux->info == num) {
                achei = true;
            } else {
                aux = aux->prox;
                cntd++; // contador para verificar a posição do número na lista
            }
        }
        if(achei) {
            cout << "Numero encontrado! Posicao: " << cntd << endl;
        } else cout << "Numero nao encontrado\n";
    }
}

void crescente() {
    imprimirLista(topo);
}

void decrescente() {
    noPtr topoPilha = NULL, p, aux;
    aux = topo;
    while(aux != NULL) {
        p = new no;
        p->prox = topoPilha;
        p->info = aux->info;
        topoPilha = p;
        aux = aux->prox;
    }
    imprimirLista(topoPilha);
}

int main() {
    int op;
    do {
        op = menu();
        switch(op) {
            case 1: inserir(); break;
            case 2: retirar(); break;
            case 3: consultar(); break;
            case 4: crescente(); break;
            case 5: decrescente(); break;
            default: break;
        }
    } while(op != 6);
    return 0;
}