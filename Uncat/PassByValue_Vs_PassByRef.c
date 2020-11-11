#include <stdio.h>

void update_byValue(int a,int b)
{
    a = a+b;
    b = a-b;
}

void update_byRef(int *a,int *b)
{
    *a = *a+*b;
    *b = *a-*b;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);

    update_byValue(a, b);
    printf("By Value: a = %d\tb = %d\n", a, b);
    update_byRef(&a, &b);
    printf("By Ref  : a = %d\tb = %d\n", a, b);
    return 0;
}
