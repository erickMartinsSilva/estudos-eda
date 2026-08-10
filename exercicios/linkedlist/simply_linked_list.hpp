#ifndef SIMPLY_LINKED_LIST_H
#define SIMPLY_LINKED_LIST_H

using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node* NodePtr;

bool simply_linked_list_is_empty(NodePtr head);
void add_to_simply_linked_list(NodePtr* head, NodePtr* tail, int data);
void remove_from_simply_linked_list(NodePtr* head, NodePtr* tail, int data);
void print_simply_linked_list(NodePtr head);
string simply_linked_list_to_string(NodePtr head);

#endif