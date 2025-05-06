#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* prev;
    struct Node* next;
}Node;

void insertAtBeginning(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> prev = NULL;

    newNode -> next = *head;

    if(*head != NULL){

        (*head) -> prev = newNode;
    }

    *head = newNode;
}

void insertAtEnd(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value; 
    newNode -> next = NULL;

    Node* temp = *head;

    //edge case

    while(temp -> next != NULL){

        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> prev = temp; 
}

void deleteBeginning(Node** head, int value){

    Node* temp = *head;

    *head = temp -> next;

    //edge case 

    free(temp);

}

void deleteEnd(Node** head){

    Node* temp = *head;

    while(temp -> next != NULL){

        temp = temp -> next;
    }

    temp -> prev -> next = NULL;
    free(temp);
}

void displayForward(Node* head){

    Node* temp = head;

    while(temp != NULL){

        printf("%d <-> ", temp -> data);
        temp = temp -> next;
    }
    
}

