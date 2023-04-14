//
// Created by MasaHiroSaber on 2023/4/5.
//

//循环链表
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct CirNode {
    int data;
    struct CirNode *next;
} CirNode;

typedef struct CircularLinkedList {
    CirNode* head;
    CirNode* tail;
    int length;
} CircularLinkedList;

CirNode *NewNode(int value) {
    struct CirNode *p = (CirNode *) malloc(sizeof(CirNode));
    if (!p) return NULL;
    p->data = value;
    p->next = NULL;
    return p;
}

CircularLinkedList *CreateCircularLinkedList() {
    auto *list = (CircularLinkedList *) malloc(sizeof(CircularLinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void InsertHead(CircularLinkedList *list, int value)
{
    CirNode *newNode = NewNode(value);
    if (list->length == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    } else
    {
        newNode->next = list->head;
        list->head = newNode;
        list->tail->next = list->head;
    }
    list->length++;
}

void InsertTail(CircularLinkedList *list, int value)
{
    CirNode *newNode = NewNode(value);
    if (list->length == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
        list->tail->next = list->head;
    }
    list->length++;
}

void Insert(CircularLinkedList *list, int index, int value)
{
    if (index < 0 || index > list->length) return;
    if (index == 0)
    {
        InsertHead(list, value);
    }
    else if (index == list->length)
    {
        InsertTail(list, value);
    }
    else
    {
        CirNode *p = list->head;
        while (index--) p = p->next;
        CirNode *newNode = NewNode(value);
        newNode->next = p->next;
        p->next = newNode;
        list->length++;
    }
}

void DeleteHead(CircularLinkedList *list)
{
    if (list->length == 0) return;
    CirNode *p = list->head;
    list->head = list->head->next;
    list->tail->next = list->head;
    free(p);
    list->length--;
}

void DeleteTail(CircularLinkedList *list)
{
    if (list->length == 0) return;
    CirNode *p = list->head;
    while (p->next != list->tail) p = p->next;
    free(list->tail);
    list->tail = p;
    list->tail->next = list->head;
    list->length--;
}

void Delete(CircularLinkedList *list, int index)
{
    if (index < 0 || index >= list->length) return;
    if (index == 0)
    {
        DeleteHead(list);
    } else if (index == list->length - 1)
    {
        DeleteTail(list);
    } else
    {
        CirNode *p = list->head;
        while (index--) p = p->next;
        CirNode *q = p->next;
        p->next = q->next;
        free(q);
        list->length--;
    }
}



