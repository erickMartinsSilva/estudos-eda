#include <iostream>
#include "simply_linked_list.hpp"

using namespace std;

bool simply_linked_list_is_empty(NodePtr head) {
    return !head;
}

void add_to_simply_linked_list(NodePtr* head, NodePtr* tail, int data) {
    NodePtr node = new Node;
    node->data = data;

    if(simply_linked_list_is_empty(*head)) {
        node->next = NULL;
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        node->next = NULL;
        *tail = node;
    }
}

void remove_from_simply_linked_list(NodePtr* head, NodePtr* tail, int data) {
    NodePtr aux = *head;
    NodePtr prev_aux = NULL;
    bool found = false;

    while(!found && aux != NULL) {
        found = aux->data == data;
        if(!found) {
            prev_aux = aux;
            aux = aux->next;
        }
    }
    if(!found) return;

    if(aux == *head) {
        *head = aux->next;
    } else if (aux == *tail) {
        *tail = prev_aux;
        prev_aux->next = NULL;
    } else {
        prev_aux->next = aux->next;
    }
    aux->next = NULL;
    delete aux;
}

void print_simply_linked_list(NodePtr head) {
    NodePtr aux = head;
    printf("[ ");
    while(aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("]\n");
}