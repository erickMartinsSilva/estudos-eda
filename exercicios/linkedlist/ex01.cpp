// Função que percorre uma lista simplesmente encadeada e retorna seu tamanho (número de elementos)
#include <iostream>
#include "simply_linked_list.hpp"

using namespace std;

int linked_list_size(NodePtr head) {
    NodePtr aux = head;
    int size = 0;
    
    while(aux != NULL) {
        size++;
        aux = aux->next;
    }
    return size;
}

void test_linked_list_size() {
    NodePtr head = NULL, tail = NULL;

    int first_result = linked_list_size(head);

    add_to_simply_linked_list(&head, &tail, 1);
    int second_result = linked_list_size(head);

    add_to_simply_linked_list(&head, &tail, 1);
    add_to_simply_linked_list(&head, &tail, 1);
    remove_from_simply_linked_list(&head, &tail, 1);
    int third_result = linked_list_size(head);

    bool passed = first_result == 0 && second_result == 1 && third_result == 2;
    if(!passed) {
        printf("Results invalid for the current implementation. Expected [0, 1, 2] and received [%d, %d, %d]\n",
            first_result, second_result, third_result
        );
        return;
    }
    printf("Passed\n");
}

int main() {
    test_linked_list_size();
}