// Função que percorre uma lista simplesmente encadeada e retorna seu tamanho (número de elementos)
#include <iostream>

using namespace std;

struct Node {
    int info;
    struct Node* next;
};

typedef struct Node* nodePtr;

int linked_list_size(nodePtr head) {
    nodePtr aux = head; int size = 0;
    while(aux != NULL) {
        size++;
        aux = aux->next;
    }
    return size;
}

bool linked_list_empty(nodePtr head_or_tail) {
    return !head_or_tail;
}

void add_to_linked_list(nodePtr* head, nodePtr* tail, int info) {
    nodePtr newNodePtr = new Node;
    newNodePtr->info = info;
    
    if(linked_list_empty(*head)) {
        newNodePtr->next = NULL;
        *head = newNodePtr;
    } else {
        (*tail)->next = newNodePtr;
        newNodePtr->next = NULL;
    }
    *tail = newNodePtr;
}

void test_linked_list_size() {
    nodePtr head = NULL, tail = NULL;

    int first_result = linked_list_size(head);

    add_to_linked_list(&head, &tail, 1);
    int second_result = linked_list_size(head);

    add_to_linked_list(&head, &tail, 1);
    add_to_linked_list(&head, &tail, 1);
    add_to_linked_list(&head, &tail, 1);
    int third_result = linked_list_size(head);

    bool passed = first_result == 0 && second_result == 1 && third_result == 4;
    if(!passed) {
        printf("Results invalid for the current implementation. Expected [0, 1, 4] and received [%d, %d, %d]\n",
            first_result, second_result, third_result
        );
        return;
    }
    printf("Passed\n");
}

int main() {
    test_linked_list_size();
}