//
// Created by MasaHiroSaber on 2023/4/14.
//

//冒泡排序

void BubbleSort(int *list, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

//选择排序

void SelectSort(int *list, int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = list[i];
            list[i] = list[min];
            list[min] = temp;
        }
    }
}

//快速排序

void QuickSort(int *list, int left, int right) {
    if (left >= right) return;
    int i = left, j = right, key = list[left];
    while (i < j) {
        while (i < j && list[j] >= key) j--;
        list[i] = list[j];
        while (i < j && list[i] <= key) i++;
        list[j] = list[i];
    }
    list[i] = key;
    QuickSort(list, left, i - 1);
    QuickSort(list, i + 1, right);
}