// Função que recebe uma lista encadeada e um número como parâmetros e remove todas as incidências do número da lista, imprimindo-a
#include <iostream>
#include "simply_linked_list.hpp"

using namespace std;

void removeFromLista(NodePtr *topo, int n) {
    NodePtr aux = *topo, ant = NULL;
    bool found = false;

    while(!found && aux != NULL) {
        found = aux->data == n;
        if(!found) {
            ant = aux;
            aux = aux->next;
        }
    }
    if(!found) return;

    if(aux == *topo) {
        *topo = aux->next;
    } else {
        ant->next = aux->next;
    }
    aux->next = NULL;
    delete aux;
}

void test_removeFromLista() {
    NodePtr head = NULL, tail = NULL;

    add_to_simply_linked_list(&head, &tail, 1);
    add_to_simply_linked_list(&head, &tail, 2);
    add_to_simply_linked_list(&head, &tail, 3);

    removeFromLista(&head, 2);

    printf("Result: ");
    print_simply_linked_list(head);
}

int main() {
    test_removeFromLista();
}