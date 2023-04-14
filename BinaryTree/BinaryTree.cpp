//
// Created by MasaHiroSaber on 2023/4/14.
//
//实现一个二叉查找树，并且支持插入、删除、查找操作

#include <stdio.h>
#include <stdlib.h>

typedef struct Binary_tree {
    int data;
    struct Binary_tree *left;
    struct Binary_tree *right;
} bt;

bt *CreateBinaryTree() {
    bt *p = (bt *) malloc(sizeof(bt));
    if (!p) return NULL;
    p->left = NULL;
    p->right = NULL;
    return p;
}

bt *Insert(bt *tree, int value) {
    if (tree == NULL) {
        tree = CreateBinaryTree();
        tree->data = value;
    } else if (value < tree->data) {
        tree->left = Insert(tree->left, value);
    } else if (value > tree->data) {
        tree->right = Insert(tree->right, value);
    }
    return tree;
}

bt *Find(bt *tree, int value) {
    if (tree == NULL) return NULL;
    if (value < tree->data) {
        return Find(tree->left, value);
    } else if (value > tree->data) {
        return Find(tree->right, value);
    } else {
        return tree;
    }
}

bt *FindMin(bt *tree) { // 找到最小值
    if (tree == NULL) return NULL;
    if (tree->left == NULL) return tree;
    return FindMin(tree->left);
}

bt *FindMax(bt *tree) { // 找到最大值
    if (tree == NULL) return NULL;
    if (tree->right == NULL) return tree;
    return FindMax(tree->right); // 递归
}

bt *Delete(bt *tree, int value) {
    bt *temp;
    if (tree == NULL) return NULL;
    if (value < tree->data) {
        tree->left = Delete(tree->left, value);
    } else if (value > tree->data) {
        tree->right = Delete(tree->right, value);
    } else if (tree->left && tree->right) {
        temp = FindMin(tree->right);
        tree->data = temp->data;
        tree->right = Delete(tree->right, tree->data);
    } else {
        temp = tree;
        if (tree->left == NULL) {
            tree = tree->right;
        } else if (tree->right == NULL) {
            tree = tree->left;
        }
        free(temp);
    }
    return tree;
}

void PreOrder(bt *tree) { // 前序遍历
    if (tree == NULL) return;
    printf("%d ", tree->data);
    PreOrder(tree->left);
    PreOrder(tree->right);
}

void InOrder(bt *tree) { // 中序遍历
    if (tree == NULL) return;
    InOrder(tree->left);
    printf("%d ", tree->data);
    InOrder(tree->right);
}

void PostOrder(bt *tree) { // 后序遍历
    if (tree == NULL) return;
    PostOrder(tree->left);
    PostOrder(tree->right);
    printf("%d ", tree->data);
}

//按层遍历

void LevelOrder(bt *tree) {
    bt *queue[100];
    int front = 0, rear = 0;
    bt *p;
    if (tree == NULL) return;
    queue[rear++] = tree;
    while (front != rear) {
        p = queue[front++];
        printf("%d ", p->data);
        if (p->left) queue[rear++] = p->left;
        if (p->right) queue[rear++] = p->right;
    }
}
//实现查找二叉查找树中某个节点的后继、前驱节点

bt *FindPre(bt *tree, int value) {
    bt *pre = NULL;
    if (tree == NULL) return NULL;
    if (value < tree->data) {
        return FindPre(tree->left, value);
    } else if (value > tree->data) {
        pre = tree;
        return FindPre(tree->right, value);
    } else {
        if (tree->left) {
            pre = FindMax(tree->left);
        }
    }
    return pre;
}

bt *FindNext(bt *tree, int value) {
    bt *next = NULL;
    if (tree == NULL) return NULL;
    if (value < tree->data) {
        next = tree;
        return FindNext(tree->left, value);
    } else if (value > tree->data) {
        return FindNext(tree->right, value);
    } else {
        if (tree->right) {
            next = FindMin(tree->right);
        }
    }
    return next;
}

