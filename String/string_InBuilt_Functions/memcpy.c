/*
C library function - memcpy()

Declaration
Following is the declaration for memcpy() function.

void *memcpy(void *dest, const void * src, size_t n)
Parameters
dest − This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.

src − This is pointer to the source of data to be copied, type-casted to a pointer of type void*.

n − This is the number of bytes to be copied.

Return Value
This function returns a pointer to destination, which is str1.

Description
The C library function void *memcpy(void *dest, const void *src, size_t n) copies n characters from memory area src to memory area dest.
*/

#include <stdio.h>
#include <string.h>

int main () {
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);

   return(0);
}

/*
Before memcpy dest = Heloooo!!
After memcpy dest = http://www.tutorialspoint.com
*/
