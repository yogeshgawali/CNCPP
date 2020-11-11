/*
C library function - memcmp()

Declaration - int memcmp(const void *str1, const void *str2, size_t n)

Parameters
str1 − This is the pointer to a block of memory.
str2 − This is the pointer to a block of memory.
n − This is the number of bytes to be compared.

Return Value
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2.

This function compares the first n bytes of memory area str1 and memory area str2.
*/

#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }

   return(0);
}

/*
str2 is less than str1
*/
