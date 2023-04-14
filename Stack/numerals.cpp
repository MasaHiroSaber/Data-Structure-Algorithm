//
// Created by MasaHiroSaber on 2023/4/14.
//

//栈实现数制转换

void Conversion(int n, int base) { //n为待转换的数，base为转换的进制
    LStack *list = CreateLStack();
    while (n) {
        Push(list, n % base);
        n /= base;
    }
    while (list->length) {
        printf("%d", Pop(list));
    }
}

//栈实现括号匹配

int Match(char *str) {
    LStack *list = CreateLStack();
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(') {
            Push(list, 1);
        } else if (str[i] == ')') {
            if (list->length == 0) return 0;
            Pop(list);
        }
        i++;
    }
    if (list->length == 0) return 1;
    return 0;
}