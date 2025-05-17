#include <stdio.h>
#include "listheader.h"

int main() {
    Node* head = NULL;

    
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printList(head);

   
    insertAtFront(&head, 0);
    printList(head);

   
    insertAt(&head, 2, 5);
    printList(head);

   
    Node* found = search(head, 3);
    if (found) {
        printf("Found node with value: %d\n", found->val);
    } else {
        printf("Value not found.\n");
    }

    
    deleteNode(&head, 2);
    printList(head);

   
    removeFront(&head);
    printList(head);

    removeBack(&head);
    printList(head);

    
    removeAt(&head, 1);
    printList(head);

    
    freeList(&head);

    return 0;
}

