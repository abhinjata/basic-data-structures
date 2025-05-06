#include <stdio.h>
#include <stdlib.h>`

#define SIZE 100

typedef struct Queue{

    int arr[SIZE];
    int front;
    int rear;
}Queue;

void init(Queue* q){

    q -> front = -1;
    q -> rear = -1;
}

int isEmpty(Queue* q){

    return q -> front == -1; 
    
}

int isFull(Queue* q){

    return q -> front == SIZE - 1;
}

void enqueue(Queue* q, int value){

    //queue overflow 

    if(isFull(q)){

        printf("Queue Overflwobroooooo");
        return;

    }
    if(q -> front == -1) q -> front = 0;
    
    q -> rear = q -> rear + 1;
    q -> arr[q -> rear] = value;
}

int dequeue(Queue* q){

    //queue underflow

    int value = q -> arr[q -> front++];
    return value;
}

//stack conversion

void copyQueue(Queue* from, Queue* to){

    while(!isEmpty(from)){

        enqueue(to, dequeue(from));
    }

}

typedef struct Stack{

    Queue q1;
    Queue q2;

}Stack;

void initStack(Stack *s){

    init(&s -> q1);
    init(&s -> q2);
}

void push(Stack* s, int value){
    
    enqueue(&s -> q2, value);
    copyQueue(&s -> q1, &s -> q2);

    Queue temp = s -> q1;
    s -> q1 = s -> q2; 
    s -> q2 = temp;
}

int pop(Stack* s){

    return dequeue(&s -> q1);
}

int main(void){

    return 0;

}