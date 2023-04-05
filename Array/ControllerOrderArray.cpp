//
// Created by MasaHiroSaber on 2023/3/29.
//

//大小固定可动态增删改的数组

#include <stdio.h>

#define MAXSIZE 20

int array[MAXSIZE];
int size = 0;

void insertElement(int value)
{
    for(int i = 0 ;i < size; i++)
    {
        if(array[i] > value)
        {
            for(int j = size; j > i; j--)
            {
                array[j] = array[j - 1];
            }
            array[i] = value;
            size++;
            return;
        }
    }
}

void deleteElement(int value)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == value)
        {
            for(int j = i; j < size; j++)
            {
                array[j] = array[j + 1];
            }
            size--;
            return;
        }
    }
}

void changeElement(int value, int newValue)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == value)
        {
            array[i] = newValue;
            return;
        }
    }
}

void printArray()
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("size = %d", size);
}

