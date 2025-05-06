#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Queue{

    int arr[SIZE];
    int front;
    int rear

}Queue;

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

        printf("Queue Overflow\n");
        return;
    }

    if(isEmpty(q)){

        q -> front = 0;
    }

    q -> rear ++;
    q -> arr[q -> rear] = value;

}

void dequeue(Queue* q, int value){

    //queue underflow edge case

    int value = q->arr[q -> front];

    q -> front ++;

    //1 item edge case

    return value;

}

int peek(Queue* q){

    return q->arr[q -> front];
}

//Linked Lists Representation

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Queue structure
typedef struct Queue {
    Node* front;  // Points to the front of the queue
    Node* rear;   // Points to the rear of the queue
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Enqueue operation - add element at the rear
void enqueue(Queue* q, int value) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = NULL;
    
    // If queue is empty, the new node is both front and rear
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        // Add the new node at the end and update rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", value);
}

// Dequeue operation - remove element from the front
int dequeue(Queue* q) {
    // Check if queue is empty
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Return a sentinel value to indicate error
    }
    
    // Store front node and value to return
    Node* temp = q->front;
    int value = temp->data;
    
    // Move front to the next node
    q->front = q->front->next;
    
    // If front becomes NULL, set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    // Free the memory of dequeued node
    free(temp);
    return value;
}

// Peek operation - view the front element without removing
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Return a sentinel value to indicate error
    }
    return q->front->data;
}

// Free the entire queue
void freeQueue(Queue* q) {
    Node* current = q->front;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    q->front = NULL;
    q->rear = NULL;
}


// Circular Queues, Priority Queues, Double 

typedef struct Node{

    int data;
    struct Node* link;

}

typedef struct CQueue{

    Node* rear;

}CQueue;

void init(CQueue* cq){

    cq -> rear = NULL;
}

int isEmpty(CQueue* cq){

    return cq -> rear == NULL;
}

void enqueue(CQueue* cq, int value){

    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;

    newNode -> link = cq -> rear -> link;
    cq -> rear -> link = newNode;
    cq -> rear = newNode;

}

int dequeue(CQueue* cq){

    int value; 

    Node* front = cq -> rear -> link;
    value = front -> data;
    cq->rear -> front  = front -> next;
    free(front);

    return value;
}