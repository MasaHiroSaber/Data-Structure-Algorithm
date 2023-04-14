//
// Created by MasaHiroSaber on 2023/4/14.
//

//实现循环队列

typedef struct CQueue {
    int *data;
    int head;
    int tail;
    int length;
} CQueue;

CQueue *CreateCQueue(int length) {
    auto *list = (CQueue *) malloc(sizeof(CQueue));
    if (!list) return NULL;
    list->data = (int *) malloc(sizeof(int) * length);
    list->head = 0;
    list->tail = 0;
    list->length = length;
    return list;
}

void EnQueue(CQueue *list, int value) {
    if ((list->tail + 1) % list->length == list->head) return; //list的长度为length-1，所以这里要判断tail+1是否等于head，
    list->data[list->tail] = value;
    list->tail = (list->tail + 1) % list->length;
}

int DeQueue(CQueue *list) {
    if (list->head == list->tail) return 0;
    int value = list->data[list->head];
    list->head = (list->head + 1) % list->length;
    return value;
}


