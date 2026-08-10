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

    string result = simply_linked_list_to_string(head);
    string expected_result = "[ 1 ] -> [ 3 ]";
    bool passed = result.compare(expected_result) == 0;
    if(!passed) {
        cout << "Failed. Expected:" << endl << expected_result << endl << "Obtained:" << endl << result << endl; 
        return;
    }
    cout << "Passed" << endl;
}

int main() {
    test_removeFromLista();
}