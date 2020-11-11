/*
C library function - memchr()

Declaration - void *memchr(const void *str, int c, size_t n)

Parameters
str − This is the pointer to the block of memory where the search is performed.
c   − This is the value to be passed as an int, but the function performs a byte
      per byte search using the unsigned char conversion of this value.
n   − This is the number of bytes to be analyzed.

Return Value
This function returns a pointer to the matching byte or NULL if the character
does not occur in the given memory area.

Description
The C library function void *memchr(const void *str, int c, size_t n) searches
for the first occurrence of the character c (an unsigned char) in the first n
bytes of the string pointed to, by the argument str.
*/

#include <stdio.h>
#include <string.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}

/*
String after |.| is - |.tutorialspoint.com|
*/
