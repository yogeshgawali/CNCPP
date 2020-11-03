#include <stdio.h>
    int add(int a, int b)
    {
        return a + b;
    }
    int main()
    {
        int (*fn_ptr)(int, int);
        fn_ptr = add;
        printf("The sum of two numbers is: %d", (int)fn_ptr(2, 3));
    }
