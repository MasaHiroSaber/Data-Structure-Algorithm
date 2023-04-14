//
// Created by MasaHiroSaber on 2023/4/14.
//

//用数组实现一个顺序队列

#include "stdio.h"

#define MAXSIZE 100

#define MAX_LENGTH 100
typedef struct Sequential_queues
{
    int sq_data[MAX_LENGTH];
    int leader;
    int tail;
} sq;

void createQueue(sq *p)
{
    p->leader = 0;
    p->tail = 0;
}

int queueEmpty(sq *p)
{
    if (p->leader == p->tail) return 1;
    else return 0;
}

int queueFull(sq *p)
{
    if (p->tail == MAX_LENGTH) return 1;
    else return 0;
}

void enterData(sq *p, int data)
{
    if (queueFull(p)) return;
    p->sq_data[p->tail] = data;
    p->tail++;
}

void deleteData(sq *p, int *data)
{
    if (queueEmpty(p)) return;
    *data = p->sq_data[p->leader];
    p->leader++;
}




