// Função que percorre uma lista simplesmente encadeada e retorna quantos elementos são maiores que um N informado pelo usuário
#include <iostream>
#include "simply_linked_list.hpp"

using namespace std;

int linked_list_amount_numbers_higher_than(NodePtr head, int number) {
    NodePtr aux = head; 
    int amount = 0;

    while(aux != NULL) {
        if(aux->data > number) {
            amount++;
        }
        aux = aux->next;
    }
    return amount;
}

void test_linked_list_amount_numbers_higher_than() {
    NodePtr head = NULL, tail = NULL;

    add_to_simply_linked_list(&head, &tail, 1);
    add_to_simply_linked_list(&head, &tail, 2);
    add_to_simply_linked_list(&head, &tail, 3);
    add_to_simply_linked_list(&head, &tail, 4);
    add_to_simply_linked_list(&head, &tail, 5);

    int result = linked_list_amount_numbers_higher_than(head, 2);
    bool passed = result == 3;
    if(!passed) {
        printf("Test failed. Expected output: 3, obtained output: %d\n", result);
        return;
    }
    printf("Passed\n");
}

int main() {
    test_linked_list_amount_numbers_higher_than();
}