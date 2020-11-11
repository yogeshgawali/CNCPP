/*
C library function - strrchr()

Declaration - char *strrchr(const char *str, const char c)

Parameters
str − This is the C string.
c   − This is the character to be located. It is passed as its int promotion, but it is internally converted back to char.

Return Value
This function returns a pointer to the last occurrence of character in str. If the value is not found, the function returns a null pointer.

Description
The C library function char *strrchr(const char *str, int c) searches for
the last occurrence of the character c (an unsigned char) in the string
pointed to, by the argument str.
*/

#include <stdio.h>
#include <string.h>

int main () {
   int len;
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}

/*
String after |.| is - |.com|
*/
