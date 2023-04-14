//
// Created by MasaHiroSaber on 2023/4/14.
//

//用数组实现一个顺序栈

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top;
} SeqStack;

SeqStack *CreateSeqStack() {
    SeqStack *p = (SeqStack *) malloc(sizeof(SeqStack));
    if (!p) return NULL;
    p->top = -1;
    return p;
}

int Push(SeqStack *stack, int value) {
    if (stack->top == MAXSIZE - 1) return 0;
    stack->data[++stack->top] = value;
    return 1;
}

int Pop(SeqStack *stack, int *value) {
    if (stack->top == -1) return 0;
    *value = stack->data[stack->top--];
    return 1;
}

int main() {
    SeqStack *stack = CreateSeqStack();
    for (int i = 0; i < 10; ++i) {
        Push(stack, i);
    }
    int value;
    while (Pop(stack, &value)) {
        printf("%d ", value);
    }
    return 0;
}

