//
// Created by MasaHiroSaber on 2023/4/14.
//

//递归实现斐波那契数列

int Fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//递归实现汉诺塔

void Hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        printf("%c->%c ", a, c);
    } else {
        Hanoi(n - 1, a, c, b);
        printf("%c->%c ", a, c);
        Hanoi(n - 1, b, a, c);
    }

}

//递归实现阶乘

int Factorial(int n) {
    if (n == 1) return 1;
    return n * Factorial(n - 1);
}

//递归实现一组数据集合的全排列

void Permutation(int *list, int k, int m)//k为当前处理的位置，m为数组的最大下标, list为数组, 从0开始, 0~m
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
        {
            printf("%d", list[i]);
        }
        printf("\n");
    } else
    {
        for (int i = k; i <= m; i++)
        {
            int temp = list[k];
            list[k] = list[i];
            list[i] = temp;
            Permutation(list, k + 1, m);
            temp = list[k];
            list[k] = list[i];
            list[i] = temp;
        }
    }

}