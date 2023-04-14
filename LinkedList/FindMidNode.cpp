//
// Created by MasaHiroSaber on 2023/4/14.
//

//实现求链表的中间结点

void FindMidNode(LinkedList *list) {
    Node *p = list->head;
    Node *q = list->head;
    while (q->next && q->next->next) { //q一次走两步，p一次走一步，当q走到尾时，p正好走到中间
        p = p->next;
        q = q->next->next;
    }
    printf("中间结点为：%d", p->data);
}