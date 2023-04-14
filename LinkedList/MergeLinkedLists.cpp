//
// Created by MasaHiroSaber on 2023/4/14.
//

//实现两个有序的链表合并为一个有序链表
#include "stdio.h"
#include "stdlib.h"

void MergeLinkedList(LinkedList *list1, LinkedList *list2, LinkedList *list3) {
    Node *p1 = list1->head;
    Node *p2 = list2->head;
    while (p1 && p2) {
        if (p1->data < p2->data) {
            InsertHead(list3, p1->data);
            p1 = p1->next;
        } else {
            InsertHead(list3, p2->data);
            p2 = p2->next;
        }
    }
    while (p1) {
        InsertHead(list3, p1->data);
        p1 = p1->next;
    }
    while (p2) {
        InsertHead(list3, p2->data);
        p2 = p2->next;
    }
}





