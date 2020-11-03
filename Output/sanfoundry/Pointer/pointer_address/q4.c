    #include <stdio.h>
    int *f();
    int main()
    {
        int *p = f();
        printf("%d\n", *p);
    }
    int *f()
    {
        int *j = (int*)malloc(sizeof(int));
        *j = 10;
        return j;
    }
