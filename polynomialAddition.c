#include <stdio.h>
#include <stdlib.h>

//core concept: if the exponent is the same, ADD

typedef struct Node{

    int value;
    int exp; 
    struct Node* link;
} Node;

Node* createNode(int value, int exp){

    Node* newNode = malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> exp = exp;
    newNode -> link = NULL;
    
    return newNode;
}

//recursive function to add two polynomials;

Node* addPoly(Node* head1, Node* head2){

    //edge case: list is empty -> pol + 0 = pol

    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    //compare the powers and recursively process the lists

    if(head1 -> exp > head2 -> exp){

        Node* nextPtr = addPoly(head1 -> link, head2);
        head1 -> link = nextPtr;
        return head1;
    }
    else if(head1 -> exp < head2 -> exp){

        Node* nextPtr = addPoly(head1, head2 -> link);
        head2 -> link = nextPtr;
        return head2;
    }
    else{

        //equal

        Node* nextPtr = addPoly(head1 -> link, head2 -> link);
        head1 -> value = head1 -> value + head2 -> value;
        head1 -> link = nextPtr;

        return head1;
    }
    
}

int main(void){

    Node* head1 = createNode(5, 2);
    head1 -> link = createNode(9, 0);

    Node* head2 = create(4, 2);
    head2 -> link = createNode(6, 1);

    Node* head = addPoly(head1, head2);
}

