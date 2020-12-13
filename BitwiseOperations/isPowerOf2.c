#include<stdio.h> ////erroer not true

int func1(int n)
{
    int count=0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main()
{
    int t, i, *list;
    scanf(" %d", &t);
    list = (int*)malloc(t*sizeof(int));
    for(i=0; i<t; i++)
        scanf(" %d", list+i);

    for(i=0; i<t; i++)
    {
        int a = func1(list[i]);
        printf("%d  ", a);
        if((a%2)==1)
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}
