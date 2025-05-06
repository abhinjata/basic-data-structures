#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Hash table size

// Node structure for linked list (Separate Chaining)
typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* hashTable[TABLE_SIZE];  // Array of linked lists (hash table)

// Hash function: simple modulo
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a value into the hash table
void insert(int value) {
    int index = hashFunction(value);

    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = hashTable[index];  // Insert at beginning
    hashTable[index] = newNode;
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    // Insert elements
    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(30);
    insert(35);
    insert(45);

    // Display table
    printf("Hash Table:\n");
    display();

    return 0;
}


typedef struct Node{

    int data; 
    struct Node* link; 

}Node; 

Node* hashTable[TABLE_SIZE];

int hashFunction(int key){

    return key % TABLE_SIZE;

}

void insert(int value){

    int index = hashFunction(value);

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value; 
    newNode -> link = hashTable[index];
    hashTable[index] = newNode;

}

void display(void){

    for(int i = 0; i < TABLE_SIZE; i++){

        printf("Index %d: ", i);
        Node* temp = hashTable[i];

        
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");

    }



}