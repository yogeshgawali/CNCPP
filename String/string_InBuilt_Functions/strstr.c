/*
C library function - strstr()

Declaration - char *strstr(const char *haystack, const char *needle)

Parameters
haystack − This is the main C string to be scanned.
needle   − This is the small string to be searched with-in haystack string.

Return Value
This function returns a pointer to the first occurrence in haystack of any
of the entire sequence of characters specified in needle, or a null pointer
if the sequence is not present in haystack.

Description
The C library function finds the first occurrence of the substring needle in
the string haystack. The terminating '\0' characters are not compared.
*/

#include <stdio.h>
#include <string.h>


int main () {
   const char haystack[50] = "Tutorials Point is a great platform.";
   const char needle[10] = "Point";
   char *ret;

   ret = strstr(haystack, needle);

   printf("The substring is: %s\n", ret);

   return(0);
}

/*
The substring is: The substring is: Point is a great platform.
*/
