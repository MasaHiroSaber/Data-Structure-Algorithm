//
// Created by MasaHiroSaber on 2023/4/5.
//

//合并两个有序数组为一个有序数组
#include <cstdio>
#include <cstdlib>

void ArrayMerging(int *m, int *n, int len_m, int len_n)
{
    int i = len_m - 1;
    int j = len_n - 1;
    int k = len_m + len_n - 1;

    while (i >= 0 && j >= 0)
    {
        if (m[i] > n[j])
        {
            m[k] = m[i];
            i--;
            k--;
        }
        else
        {
            m[k] = n[j];
            j--;
            k--;
        }
    }
    while (j >= 0)
    {
        m[k] = n[j];
        j--;
        k--;
    }
}


int main()
{
    int len_m = 6;
    int len_n = 4;
    int *m = (int *)malloc(len_m * sizeof(int));
    int *n = (int *)malloc(len_n * sizeof(int));
    m[0] = 2;
    m[1] = 3;
    m[2] = 4;
    m[3] = 7;
    m[4] = 9;
    m[5] = 11;
    n[0] = 1;
    n[1] = 4;
    n[2] = 5;
    n[3] = 10;
    m = (int *)realloc(m, (len_m + len_n) * sizeof(int));
    for(int i=len_m;i<len_m+len_n;i++)
    {
        m[i]=0;
    }

    ArrayMerging(m, n, len_m, len_n);
    for (int i = 0; i < len_m + len_n; i++)
    {
        printf("%d ", m[i]);
    }
    return 0;
}

