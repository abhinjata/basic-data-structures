#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* link;
}Node;

Node* createHeader(){

    Node* header = malloc(sizeof(Node));
    header -> data = 0;
    header -> link = NULL;
    return header;

}

void insertAtBeginning(Node* header, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> link = header -> link;
    header -> link = newNode;
    header -> data++;

}

void displayList(Node* header){

    Node* temp = header -> link;

    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }
    
}

