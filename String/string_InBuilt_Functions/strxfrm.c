/*
C library function - strxfrm()

Declaration - size_t strxfrm(char *dest, const char *src, size_t n)

Parameters
dest − This is the pointer to the destination array where the content
       is to be copied. It can be a null pointer if the argument for n is zero.
src  − This is the C string to be transformed into current locale.
n    − The maximum number of characters to be copied to str1.

Return Value
This function returns the length of the transformed string, not including
the terminating null-character.

Description
The C library function transforms the first n characters of the string src
into current locale and place them in the string dest.
*/

#include <stdio.h>
#include <string.h>

int main () {
   char dest[20] = "Hello world. This is a new beginning.";
   char src[20];
   int len;

   strcpy(src, "Tutorials Point");
   len = strxfrm(dest, src, 20);

   printf("Length of string |%s| is: |%d|", dest, len);

   return(0);
}

/*
Length of string |Tutorials Point| is: |15|
*/
