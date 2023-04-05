//
// Created by Masa HiroSaber on 2023/3/29.
//

//�ɶ�̬��չ������
#include <stdio.h>
#include "stdlib.h"

typedef struct
{
    int *data;   //������׵�ַ
    int size;    //����Ĵ�С
    int capacity;//���������
} Array;

void initArray(Array *arr, int capacity)//��ʼ������
{
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

void insertArray(Array *arr, int index, int value)//����Ԫ��
{
    if (index < 0 || index > arr->size)
    {
        printf("����λ�ò��Ϸ�");
        return;
    }
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    for (int i = arr->size - 1; i >= index; i--)
    {
        arr->data[i + 1] = arr->data[i];
    }
    arr->data[index] = value;
    arr->size++;
}

void deleteArray(Array *arr, int index)
{
    if (index < 0 || index >= arr->size)
    {
        printf("ɾ��λ�ò��Ϸ�");
        return;
    }
    for (int i = index + 1; i < arr->size; i++)
    {
        arr->data[i - 1] = arr->data[i];
    }
    arr->size--;
}

void printArray(Array *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main()
{
    Array arr;
    initArray(&arr, 10);
    for (int i = 0; i < 10; i++)
    {
        insertArray(&arr, i, i);
    }
    printArray(&arr);
    insertArray(&arr, 5, 100);
    printArray(&arr);
    deleteArray(&arr, 5);
    printArray(&arr);
    return 0;
}