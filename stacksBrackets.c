#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Stack{

    char arr[MAX];
    int top;
}Stack;

void init(Stack* s){

    s -> top = -1;
}

int isEmpty(Stack* s){

    return s -> top == -1;
}

int isFull(Stack* s){

    return s->top == MAX - 1;

}

void push(Stack* s, char value){

    if(isFull(s)){
        printf("Stack Overflow!");
        
    }

    s -> top = s -> top + 1;
    return s->arr[s -> top] = value;

}

char pop(Stack* s){

    if(isEmpty(s)){

        printf("Stack Underflow");
        return;
    }

    return s->arr[s->top--];

}

char peek(Stack* s){

    return s -> arr[s -> top];

}

int isMatching(char open, char closed){

    return (open == '(' && closed == ')') || (open == '{' && closed == '}') || (open == '[' && closed == ']');
}

int isBalanced(const char* expr){

    Stack s;
    init(&s);

    for(int i = 0; expr[i] != '\0'; i++){

        char ch = expr[i];

        if(ch == '(' || ch == '{' || ch == '['){

            push(&s, ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){

            char topChar = pop(&s);

            if(!isMatching(ch, topChar)) return 0;

        }

    }

    return isEmpty(&s);

}

