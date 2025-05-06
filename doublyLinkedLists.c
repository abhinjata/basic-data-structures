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
    newNode-> next = *head;

    if(*head != NULL){

        (*head) -> prev = newNode;
    }

    *head = newNode;
}

void insertAtEnd(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;

    if(*head == NULL){

        newNode -> prev = NULL;
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while(temp -> next != NULL){
        
        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> prev = temp;
}

void deleteBeginning(Node** head){

    Node* temp = *head;

    *head = temp -> next;

    if(*head != NULL){

        (*head)->prev = NULL;
    }

    free(temp);
}

void deleteEnd(Node** head){

    Node* temp = head;

    while(temp -> next != NULL){

        temp = temp -> next;
    }

    temp -> prev -> next = NULL;
    free(temp);
}

void displayForward(Node* head){

    while(head -> next != NULL){

        head = head -> next;
    }

    while(head != NULL){

        printf("%d <-> ", head -> data);
        head = head -> prev;
    }
    prtinf("NULL\n");
    
}

void searchElement(Node* head, int key){

    int pos = 0;
    while(head != NULL){

        if(head -> data == key){

            printf("Element %d found at position &d\n", key, pos);
            return;
        }
        head = head -> next;
        pos++;
    }
    printf("Elemetn not found");

}

