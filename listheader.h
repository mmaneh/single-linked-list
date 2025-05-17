#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int value);

void insertAtEnd(Node** head, int value);
void insertAtFront(Node** head, int value);
void insertAt(Node** head, int index, int value);

void deleteNode(Node** head, int value);

void removeFront(Node** head);
void removeBack(Node** head);
void removeAt(Node** head, int index);

Node* search(Node* head, int value);

void printList(Node* head);

void freeList(Node** head);

#endif

