#include <stdio.h>

#define to_find_size(object) (char *)(&object+1) - (char *)(&object)

int main()
{
   int x;
   char a[50];
   printf("Integer size : %d\n", to_find_size(x));
   printf("Character size : %d\n", to_find_size(a));
   return 0;
}

/*
Integer size : 4
Character size : 50
*/
