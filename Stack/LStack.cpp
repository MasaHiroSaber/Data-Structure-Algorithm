//
// Created by MasaHiroSaber on 2023/4/14.
//

//用链表实现一个链式栈

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LStack {
    Node *top;
    int length;
} LStack;

Node *NewNode(int value) {
    auto *p = (Node *) malloc(sizeof(Node));
    if (!p) return NULL;
    p->data = value;
    p->next = NULL;
    return p;
}

LStack *CreateLStack() {
    auto *list = (LStack *) malloc(sizeof(LStack));
    if (!list) return NULL;
    list->top = NULL;
    list->length = 0;
    return list;
}

void Push(LStack *list, int value) {
    Node *newNode = NewNode(value);
    if (list->length == 0)
    {
        list->top = newNode;
    } else
    {
        newNode->next = list->top;
        list->top = newNode;
    }
    list->length++;
}

int Pop(LStack *list) {
    if (list->length == 0) return 0;
    Node *p = list->top;
    list->top = p->next;
    int value = p->data;
    free(p);
    list->length--;
    return value;
}

