#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Stack{

    int arr[MAX];
    int top;
}Stack;

void init(Stack* s){

    s->top = -1;
}

bool isEmpty(Stack* s){

    if(s ->top == -1){

        return true;

    }
    else return false;
}

bool isFull(Stack* s){

    if(s -> top == MAX - 1) return true;
    else return false;
}

void push(Stack* s, int value){

    if(isFull(s) == true){

        printf("Stack Overflow!");
        return;
    }

    s -> top = s -> top + 1;
    s -> arr[s -> top] = value;
}

void pop(Stack* s, int value){

    if(isEmpty(s) == true){
        printf("Stack Underflow");
        return -1;
    }
    
    return s -> arr[s -> top--];

}

int peek(Stack* s){

    if(isEmpty(s) == true){
        printf("Stack is empty");
        return -1;
    }
    return s->arr[s->top];
}

void display(Stack* s){

    if(isEmpty(s) == true){
        printf("shit's empty");
        return;
    }

    for(int i = s -> top; i >= 0; i--){

        printf(" | %d | ", s -> arr[i]);
        printf("\n");
    }
    printf("\n");

}

