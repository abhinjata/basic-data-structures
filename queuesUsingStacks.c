#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack{

    int arr[MAX];
    int top;
} Stack;

void init(Stack* s){

    s -> top = -1;
}

int isEmpty(Stack* s){

    return s -> top == -1;
}

int isFull(Stack* s){

    return s -> top = MAX - 1;
}

void push(Stack* s, int value){

    if(isFull(s)){

        printf("Stack Overflow \n");
        return;
    }

    s -> top = s -> top + 1;
    s -> arr[s -> top] = value;
    
}

int pop(Stack* s){

    if(isEmpty(s)){

        printf("Stack Underflow \n");
        return;
    }

    return s -> arr[s -> top--];
}

int peek(Stack* s){

    if(isEmpty(s)) return -1;
    return s -> arr[s -> top];
    
}

typedef struct Queue{

    Stack s1;
    Stack s2;

}Queue;

void initQueue(Queue* q){

    init(&q -> s1);
    init(&q -> s2);

}

void enqueue(Queue* q, int value){

    push(&q -> s1, value);

}

void dequeue(Queue* q){

    if(isEmpty(&q -> s1) && isEmpty(&q -> s2)){

        printf("ntighing here");
        return -1;
    }

    if(isEmpty(&q -> s2)){
        while(!isEmpty(&q -> s1)){

            int temp = pop(&q -> s1);
            push(&q ->s2, temp);
            
        }


    }
    return pop(&q -> s2);

}
