// Função que concatena duas listas simplesmente encadeadas

#include <iostream>
#include "simply_linked_list.hpp"

using namespace std;

void concatenate_linked_lists(NodePtr tail1, NodePtr head2) {
    tail1->next = head2;
}

void test_concatenate_linked_lists() {
    NodePtr head1 = NULL, tail1 = NULL;
    NodePtr head2 = NULL, tail2 = NULL;

    add_to_simply_linked_list(&head1, &tail1, 1);
    add_to_simply_linked_list(&head1, &tail1, 2);
    add_to_simply_linked_list(&head1, &tail1, 3);
    add_to_simply_linked_list(&head1, &tail1, 4);
    add_to_simply_linked_list(&head1, &tail1, 5);

    add_to_simply_linked_list(&head2, &tail2, 6);
    add_to_simply_linked_list(&head2, &tail2, 7);
    add_to_simply_linked_list(&head2, &tail2, 8);

    concatenate_linked_lists(tail1, head2);

    string result = simply_linked_list_to_string(head1);
    string expected_result = "[ 1 ] -> [ 2 ] -> [ 3 ] -> [ 4 ] -> [ 5 ] -> [ 6 ] -> [ 7 ] -> [ 8 ]";
    bool passed = result.compare(expected_result) == 0;
    if(!passed) {
        cout << "Failed. Expected: " << endl << expected_result << endl << "Obtained: " << endl << result << endl;
        return;
    }
    cout << "Passed" << endl;
}

int main() {
    test_concatenate_linked_lists();
}