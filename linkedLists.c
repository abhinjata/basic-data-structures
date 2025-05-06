#include <stdio.h>
#include <stdlib.h>

/*Write a C program that performs the following operations on a Singly Linked List:

1. Insert a node at the beginning

2. Insert a node at the end

3. Insert a node at a given position

4. Delete a node from the beginning

5. Delete a node from the end

6. Delete a node at a given position

7. Search for an element in the linked list

8. Display the linked list

9. Exit the program*/

typedef struct Node{
    
    int data;
    struct Node* link;

}Node;

//1
void insertAtBeginning(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> link = *head;
    *head = newNode;

}

//2
void insertatEnd(Node* head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> link = NULL;

    Node* temp = head; 
    while(temp->link != NULL){

        temp = temp -> link;

    }
    temp -> link = newNode;

}

//3
void insertinAfter(Node* prevNode, int value){

    if(prevNode == NULL) return;

    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = prevNode -> link; //update the link to the link which the prevNode had
    prevNode -> link = newNode; //update the link of the prevNode

}

//4
void deleteHead(Node** head, int value){

    Node* temp = *head;
    *head = (*head)->link; //move the head to the next node
    free(temp);

}

//5
void deleteEnd(Node** head, int value){

    Node* temp = *head;
    Node* prev = NULL;

    while(temp -> link != NULL){

        prev = temp;
        temp = temp -> link;
    }

    free(temp);
}

//6
void deleteNode(Node** head, int value){

    Node* temp = *head;
    Node* prev = NULL;

    if(temp != NULL && temp -> data == value){

        *head = temp -> link;
        free(temp);
        return;

    }

    while(temp != NULL && temp -> data == value){

        prev = temp;
        temp = temp->link;

    }
    
    if(temp == NULL) return;

    prev -> link = temp -> link;
    free(temp); //converts the temp into the node in consideration and frees it from the memory
}

int main(void){

    int search;
    scanf("%d", &search);   

    Node* head = malloc(sizeof(Node));
    head -> data = 45;
    head -> link = NULL;

    Node* second = malloc(sizeof(Node));
    second -> data = 98;
    second -> link = NULL;

    head -> link = second;

    Node* third = malloc(sizeof(Node));
    third -> data = 102;
    third -> link = NULL;

    second -> link = third;

    Node* temp = head; 

    insertAtBeginning(&head, 1);
    insertatEnd(head, 200);
    insertinAfter(second, 500);

    temp = head; 

    int position = 0;
    int flag = 0;

    //7    <------------
    while(temp != NULL){

        if(temp -> data == search){

            printf("Found at %d", position);
            flag = 1;
            break;
        }

        position = position + 1;
        temp = temp -> link;

    }
    printf("NULL\n");

    //printing
    
    while(temp != NULL){

        printf("%d -> ", temp-> data);
        temp = temp -> link;

    }
    printf("NULL\n");

    //counting elems

    Node* temp2 = head;
    int count = 0;

    while(temp2 != NULL){

        count++;
        temp2 = temp2 -> link;

    }
    printf("%d", count);

}

typedef struct Node{

    int data;
    struct Node* link;

}Node;

insertAtBeginning(Node* head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = 214;
    newNode -> link = head;
    head = newNode;

}

insertinAfter(Node* prevNode, int value){

    if(prevNode == NULL) return;

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = 43;
    newNode -> link = prevNode -> link;
    prevNode -> link = newNode;
}

insertatEnd(Node* head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = 143;
    newNode -> link = NULL;

    Node* temp = head;

    while(temp -> link != NULL){

        temp = temp -> link;

    }

    temp -> link = newNode;

}

void deleteNode(Node** head, int value){

    Node* temp = *head;
    Node* prev = NULL;

    if(temp != NULL && temp -> data == value){

        *head = temp -> link;
        free(temp);
        return;

    }

    while(temp != NULL && temp -> data == value){

        prev = temp;
        temp = temp->link;

    }
    
    if(temp == NULL) return;

    prev -> link = temp -> link;
    free(temp);
}

int main(void){

    Node* head = malloc(sizeof(Node));
    head -> data = 45;
    head -> link = NULL;

    Node* second = malloc(sizeof(Node));
    second -> data = 56;
    second -> link = NULL;

    head -> link = second;

    Node* third = malloc(sizeof(Node));
    third -> data = 32;
    third -> link = NULL;

    second -> link = third;

    Node* temp = head;

    insertAtBeginning(&head, 5);
    insertinAfter(second, 120);
    insertatEnd(head, 200);

    
    while(temp != NULL){

        printf("%d -> ", temp -> data);
        temp = temp -> link;

    }
    printf("NULL\n");

    Node* temp2 = head;
    int count = 0;

    while(temp2 != NULL){

        count++;
        temp2 = temp2 -> link;
        
    }

}