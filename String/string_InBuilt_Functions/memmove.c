/*
Description
The C library function copies n characters from str2 to str1, but for
overlapping memory blocks, memmove() is a safer approach than memcpy().

Declaration - void *memmove(void *str1, const void *str2, size_t n)

Parameters
str1 − This is a pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
str2 − This is a pointer to the source of data to be copied, type-casted to a pointer of type void*.
n    − This is the number of bytes to be copied.

Return Value
This function returns a pointer to the destination, which is str1.
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100] = "Learning is fun!";
    char *first, *second;
    first = str;
    second = str;
    printf("Original string : %s\n", str);

    // when overlap happens then it just ignore it
    memcpy(first + 8, first, 10);
    printf("memcpy overlap  : %s\n", str);

    // when overlap it start from first position
    memmove(second + 8, first, 10);
    printf("memmove overlap : %s\n", str);

    return 0;
}
