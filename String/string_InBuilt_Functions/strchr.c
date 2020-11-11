C library function - strchr()
Advertisements


 Previous PageNext Page
Description
The C library function char *strchr(const char *str, int c) searches for the first occurrence of the character c (an unsigned char) in the string pointed to by the argument str.

Declaration
Following is the declaration for strchr() function.

char *strchr(const char *str, int c)
Parameters
str − This is the C string to be scanned.

c − This is the character to be searched in str.

Return Value
This returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.

Example
The following example shows the usage of strchr() function.

Live Demo
#include <stdio.h>
#include <string.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
Let us compile and run the above program that will produce the following result −

String after |.| is - |.tutorialspoint.com|
