#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Linked Lists

typedef struct Node{

    int data;
    struct Node* link;

} Node; 


void insertAtBeginning(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> link = *head;
    *head = newNode;

}

void insertAtEnd(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> link = NULL;

    Node* temp = head;

    while(temp -> link != NULL){

        temp = temp -> link;

    }

    temp -> link = newNode;
}

void insertAtPosition(Node* prevNode, int value){

    if(prevNode == NULL) return;
    
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> link = prevNode -> link;
    prevNode -> link = newNode;

}

void deleteHead(Node** head, int value){

    Node* temp = *head;
    *head = (*head)-> link;
    free(temp);

}

void deleteNode(Node** head, int value){

    Node* temp = *head;
    Node* prev = NULL;

    // if the node is head 
    if(temp != NULL && temp -> data == value){
        
        *head = temp -> link;
        free(temp);
        return;
    }

    // find the node 

    while(temp != NULL && temp -> data == value){

        prev = temp;
        temp = temp -> link;

    }

    if(temp == NULL) return; 

    prev -> link = temp -> link;
    free(temp);

}

void insertAtBeginning(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    
    //edge case
    if(*head == NULL){

        newNode -> link = newNode;
        *head = newNode;
        return;

    }

    //to insert at the beginning, you need to get a link/thread to the end and then declare newNode's link as the head and tie the head with the end that you just got

    Node* temp = *head;

    while(temp -> link != *head){

        temp = temp -> link;
    }

    newNode -> link = *head;
    temp -> link = newNode;
    *head = newNode; 


}

void insertAtBeginning(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    
    //edge case

    // get a thread first

    Node* temp = *head;

    while(temp -> link != *head){

        temp = temp -> link;
    }

    newNode -> link = *head;
    temp -> link = newNode;
    *head = newNode;

} 

void insertAtEnd(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;

    //edge case

    if(*head == NULL){

        newNode -> link = newNode;
        *head = newNode;
        return;
    }

    //thread

    Node* temp = *head;

    while(temp -> link != *head){   

        temp = temp -> link;
    }

    temp -> link = newNode;
    newNode -> link = *head;

}

void deleteBeginning(Node** head, int value){

    if(*head == NULL) return;

    Node* temp = *head;

    Node* last = *head;
    
    while(last -> link != *head){

        last = last -> link;
    }

    last -> link = temp -> link;
    *head = temp -> link;

    free(temp); 

}


void deleteBeginning(Node** head, int value){

    if(*head == NULL) return;

    Node* temp = *head;

    Node* last = *head;

    while(last -> link != *head){

        last = last -> link;
    }

    last -> link = temp -> link;
    *head = temp -> link;

    free(temp);
}

void deleteEnd(Node** head){

    if(*head == NULL) return;

    Node* temp = *head;

    //edge case: singleton

    Node* prev = *head;

    while(temp -> link != *head){

        prev = temp;
        temp = temp -> link;
    }

    prev -> link = *head;
    free(temp);

}

void displayList(Node* head){

    Node* temp = head;

    while(temp != head){

        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }
}

void searchElement(Node* head, int key){

    Node* temp = head;

    int pos = 0;

    while(temp != head){

        if(temp -> data == key){

            printf("👍 at %d", pos);
        }

        temp = temp -> link;
        pos = pos + 1;
    }
    printf("💔");
}

typedef struct Node{

    int value;
    int pow;
    struct Node* link;
}Node; 

Node* createNode(int value, int pow){

    Node* newNode = malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> pow = pow;
    newNode -> link = NULL;

    return newNode;

}

Node* addPoly(Node* head1, Node* head2){

    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    if(head1 -> pow > head2 -> pow){

        Node* whosNext = addPoly(head1 -> link, head2);
        head1 -> link = whosNext;
        return head1;

    }

    else if(head1 -> pow < head2 -> pow){

        Node* whosNext = addPoly(head1, head2 -> link);
        head2 -> link = whosNext;
        return head2;

    }

    else{

        head1 -> value = head1 -> value + head2 -> value; 

        Node* whosNext = addPoly(head1 -> link, head2 -> link);
        head1 -> link = whosNext;

        return head1;
    }

}

typedef struct Node{

    int value; 
    int expo;
    struct Node* link;
}Node;

Node* createNode(int value, int expo){

    Node* newNode = malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> expo = expo;
    newNode -> link = NULL;
}

Node* addPoly(Node* poly1, Node* poly2){

    if(poly1 == NULL) return poly2;
    if(poly2 == NULL) return poly1;

    if(poly1 -> expo > poly2 -> expo){

        Node* whosNext = addPoly(poly1 -> link, poly2);
        poly1 -> link = whosNext;
        return poly1; 
    }

    else if(poly1 -> expo < poly2 -> expo){

        Node* whosNext = addPoly(poly1, poly2 -> link);
        poly2 -> link = whosNext;
        return poly2;
    }

    else{

        poly1 -> value = poly1 -> value + poly2 -> value;

        Node* whosNext = addPoly(poly1 -> link, poly2 -> link);
        poly1 -> link = whosNext;

        return poly1;

    }
    
}

typedef struct Node{

    int value;
    struct Node* link;
}Node;

Node* insertAtBeginning(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> link = *head;
    *head = newNode;
}

Node* insertAtEnd(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> link = NULL;

    Node* temp = head; 
    while(temp -> link != NULL){

        temp = temp -> link;

    }

    temp -> link = newNode;
}

void insertInAfter(Node* prevNode, int value){

    if(prevNode == NULL) return; 

    Node* newNode = malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> link = prevNode -> link;
    prevNode -> link = newNode;
}

void deleteHead(Node** head){

    Node* temp = *head;
    *head = (*head) -> link;
    free(temp);
}

void deleteEnd(Node** head){

    Node* temp = *head;
    Node* prev = NULL;

    while(temp -> link != NULL){

        prev = temp;
        temp = temp -> link;
    }

    free(temp);
}

void deleteNode(Node** head, int value){

    Node* temp = *head;
    Node* prev = NULL;

    while(temp != NULL && temp -> data == value){

        prev = temp;
        temp = temp -> link;
    }

    prev -> link = temp -> link;
    free(temp);
}

void searchList(Node* head, int target){

    Node* temp = head;
    int pos = 0;

    while(temp != NULL){

        if(target -> value == target){

            break;
            flag = 1;

        }
        //found

        temp = temp -> link;
        pos = pos + 1;
    }

}

typedef struct Node{

    int data;
    struct Node* link;
    
}Node;

void insertAtBeginning(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;

    Node* temp = *head;

    while(temp -> link != *head){

        temp = temp -> link;

    }

    newNode -> link = *head;
    temp -> link = newNode;
    *head = newNode;

}

void insertAtEnd(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;

    Node* temp = *head;

    while(temp -> link != *head){

        temp = temp -> link;

    }

    temp -> link = newNode;
    newNode -> link = *head;
    
} 

void deleteBeginning(Node** head){

    if(*head == NULL) return;

    Node* temp = *head;

    if(temp -> link == *head){

        free(temp);
        *head = NULL;
        return;
    }

    Node* last = *head;

    while(last -> link != *head){

        last = last -> link;

    }

    last -> link = temp -> link;
    *head = temp -> link;

    free(temp);
}

void deleteEnd(Node** head){

    Node* temp = *head;

    Node* prev = *head;

    while(temp -> link != *head){

        prev = temp;
        temp = temp -> link;
    }

    prev -> link = *head;
    free(temp);
}

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
    *head = newNode;

}

void insertAtEnd(Node** head, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;

    Node* temp = *head; 
    while(temp -> link != NULL){
        
        temp = temp -> link;
    }

    newNode -> prev = temp;
    temp -> link = newNode;
}

void deleteBeginning(Node** head){

    Node* temp = *head;

    *head = temp -> link;

    free(temp);

}

void deleteEnd(Node** head){

    Node* temp = *head;

    while(temp -> link != NULL){

        temp = temp -> link;
    }

    temp -> prev -> next = NULL;

    free(temp);
    
}

void displayForward(Node* head){

    while(head -> link != NULL){

        head = head -> link;
    }

    Node* temp = head;

    while(head != NULL){

        printf("%d <-> ", temp -> data);
        temp = temp -> next;
       
    }

}

#define MAX 100

typedef struct Stack{

    int top;
    int arr[MAX];

}Stack;

void initStack(Stack* s){

    s -> top = -1 
}

int isEmpty(Stack* s){

    return s -> top == -1;

}

int isFull(Stack* s){

    return s -> top == MAX - 1;
}

void push(Stack* s, int value){

    //stack overflow

    s -> top  = s -> top + 1;
    s -> arr[s -> top] =  value;
}

void pop(Stack* s){

    return s -> arr[s -> top--];
}

int peek(Stack* s){

    return s -> arr[s -> top];
}

typedef struct Node{

    int top;
    int arr[MAX];
}Stack;

void init(Stack* s){
    s -> top = -1;
}

int isFull(Stack* s){

    return s -> top == MAX -1;
}

int isEmpty(Stack* s){

    return s -> top == -1;
}

void push(Stack* s, int value){

    //stack overflow

    s -> top++;
    s -> arr[s -> top] = value;
}

void pop(Stack* s){

    return s -> arr[s -> top--];
}

int peek(Stack* s){

    return s -> arr[s -> top];
}

typedef struct Queue{

    Stack s1;
    Stack s2;
}Queue;

void initQ(Queue* q){

    init(&q -> s1);
    init(&q -> s2);
}

void enqueue(Queue* q, int value){

    push(&q -> s1, value);

}

void dequeue(Queue* q){

    if(isEmpty(&q -> s2)){

        while(!isEmpty(&q ->s1)){

            int temp = pop(&q -> s1);
            push(&q -> s2)

        }

    }

    pop(&q->s2);

}

#define SIZE 100

typedef struct Queue{

    int arr[SIZE];
    int front;
    int rear;
} Queue;


void initQueue(Queue* q){

    q -> front = -1;
    q -> rear = -1;
}

int isEmpty(Queue* q){

    return q -> front == -1;
}

int isFull(Queue* q){

    return q -> rear == -1;
}

void enqueue(Queue* q, int value){

    if(isFull(q)){

        //qoverflow

    }

    q -> rear ++;
    q -> arr[q -> rear] = value;
}

void dequeue(Queue* q){

    int value = q -> arr[q -> front];
    q -> front ++;

    return value;
}


int peek(Queue* q){

    return q -> arr[q -> front];
}

// linked list time

typedef struct Node{

    int data; 
    struct Node* link;

}Node;

typedef struct Queue{

    Node* front;
    Node* rear;

}Queue;

void initQueue(Queue* q){

    q -> front = NULL;
    q -> rear = NULL; 
}

int isEmpty(Queue* q){

    return q -> front == NULL;
}

void enqueue(Queue* q, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> link = NULL;

    q -> rear -> link = newNode;
    q -> rear = newNode;
}

void dequeue(Queue* q){

    Node* temp = q -> front; 
    int value = temp -> front;

    q -> front = q -> front -> link;

    free(temp);

}

void copySendQ(Queue* to, Queue* from){

    while(!isEmpty(from)){

        enqueue(to, dequeue(from));
    }

}

void push(Stack* s, int value){

    
    push(&s -> q2, value);
    copySendQ(&s -> q1, &s -> q2);

    Queue temp = s -> q1;
    s -> q1 = s -> q2;
    s -> q2 = temp;

}

typedef struct treeNode{

    int data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

treeNode* createNode(int value){

    treeNode* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void insertNode(treeNode** root, int value){

    treeNode* newNode = malloc(sizeof(treeNode));
    
    treeNode* queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = *root;

    while(front < rear){

        TreeNode* current = queue[front++];

        //Left side

        if(current -> left == NULL){

            current -> left = newNode;
            return;
        }

        else{

            queue[rear++] = current -> left;

        }
    
        // Right 

        if(current -> right == NULL){

            current -> right = newNode;
            return;

        }

        else{

            queue[rear++] = current -> right;
            
        }

    }
    
}

void insertNode(treeNode** root, int value){

    treeNode* newNode = malloc(sizeof(treeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    treeNode* queue[100];

    int front = 0;
    int rear = 0;

    treeNode* queue[rear++] = *rear;

    while(front < rear){

        treeNode* current = queue[front++];

        if(current -> left == NULL){

            current -> left = newNode;
            return;
        }

        else{

            queue[rear++] = current -> left;

        }

        if(current -> right == NULL){

            current -> right == newNode;
            return;
        }
        
        else{

            queue[rear++] = current -> right;
        }
        
    }

}

void inorderTraversal(TreeNode* root){

    preorderTraversal(root -> left);
    printf("%d ", root -> data);
    preorderTraversal(root -> right);
    
}

void postorderTraversal(treeNode* root){

    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    printf("%d ", root -> data);

}

void preorderTraversal(treeNode* root){

    printf("%d ", root -> data);
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

typedef struct treeNode{

    int data; 
    struct treeNode* left;
    struct treeNode* right;

}