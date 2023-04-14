//
// Created by MasaHiroSaber on 2023/4/14.
//

//用链表实现一个链式队列

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LQueue {
    Node *front;
    Node *rear;
    int length;
} LQueue;

Node *NewNode(int value) {
    auto *p = (Node *) malloc(sizeof(Node));
    if (!p) return NULL;
    p->data = value;
    p->next = NULL;
    return p;
}

LQueue *CreateLQueue() {
    auto *list = (LQueue *) malloc(sizeof(LQueue));
    if (!list) return NULL;
    list->front = NULL;
    list->rear = NULL;
    list->length = 0;
    return list;
}

void EnQueue(LQueue *list, int value) {
    Node *newNode = NewNode(value);
    if (list->length == 0)
    {
        list->front = newNode;
        list->rear = newNode;
    } else
    {
        list->rear->next = newNode;
        list->rear = newNode;
    }
    list->length++;
}

int DeQueue(LQueue *list) {
    if (list->length == 0) return 0;
    Node *p = list->front;
    list->front = p->next;
    int value = p->data;
    free(p);
    list->length--;
    return value;
}

