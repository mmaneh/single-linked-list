#include <stdio.h>
#include <stdlib.h>
#include "listheader.h"

Node* createNode(int value) {
Node* ptr = (Node*)malloc(sizeof(Node));
	if (!ptr){
		return NULL;
	}
	ptr->val = value;
	ptr->next = NULL;

	return ptr;
}

void insertAtEnd(Node**head, int value) {
	Node* ptr = *head;
	Node*  newnode = createNode(value);
	if (!(*head)) {
		*head = newnode;
	    return;
	}
	
	while (ptr->next) {
		ptr = ptr->next;
	}
	ptr->next = newnode;
	return;
}
void insertAtFront(Node **head, int value) {
	Node *tmp = *head;
	Node* newnode = createNode(value);

//	if(!(*head)) {
//		*head = newnode;
//	}
	newnode->next = *head;
	*head = newnode;
	return;	
}

void insertAt(Node** head, int index, int value) {
	Node* newnode = createNode(value);

	if (index < 0){
		return;
	}
	if (index == 0) {
		insertAtFront(head, value);
		return;
	}
	Node* tmp = *head;
	while (index > 1) {
	if (!tmp) return;
		tmp = tmp->next;
		--index;
	}
	newnode->next = tmp->next;
	tmp->next = newnode;	
}

void deleteNode (Node** head, int value) {
	if (!(*head)) {
	 return;
	}
	Node* ptr = *head;
	if (ptr->val == value) {
		*head = ptr->next;
		free(ptr);
		return;
	}
	while (ptr->next) {
        	if (ptr->next->val == value) {
          		 Node* temp = ptr->next;
           	 	ptr->next = temp->next;
           		 free(temp);
        	   	 break;
	      	} else {
		    ptr = ptr->next;	
		}
	}
   
	return;
}
        
void removeFront(Node** head) {
	if (!(*head)) {
		return;
	}
	Node* ptr = *head;
	*head = ptr->next;
	free(ptr);

	return;
}

void removeBack(Node** head) {
	if (!(*head)) return;
	
        Node* ptr = *head;
        
        while(ptr->next->next) {
                ptr = ptr->next;
        }
	free(ptr->next);
	ptr->next = NULL;

}

void removeAt(Node** head, int index) {
	Node* ptr = *head;
	if (!(*head) || index < 0) return;
	if(index == 0) {
		removeFront(head);
		return;
	}

	while (index > 1 && ptr->next) {
		ptr = ptr->next;
		--index;
	}

	if (ptr->next){
		Node* tmp = ptr->next;
		ptr->next = tmp->next;
		free(tmp);
	}
	return;

}

Node* search(Node *head, int value) {
	Node* ptr = head;
	if (!head) {
		printf("List is empty\n");
		return NULL;
	}

	while(ptr) {
		if(ptr->val == value) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void printList(Node* head) {
	if(!head) {
		printf("The list is empty\n");
		
		return;
	}

	Node* ptr = head;

	while (ptr) {
		printf("%d ", ptr->val);
		ptr = ptr->next;
		
	}
	printf("\n");
	return;
}

void freeList(Node** head) {
	if(!(*head)) return;
	Node* ptr = *head;
	Node* tmp;

	while (ptr) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*head = NULL;
	
	return;
}
