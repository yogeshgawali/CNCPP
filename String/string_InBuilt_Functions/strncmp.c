/*
C library function - strncmp()

Declaration - int strncmp(const char *str1, const char *str2, size_t n)

Parameters
str1 − This is the first string to be compared.
str2 − This is the second string to be compared.
n    − The maximum number of characters to be compared.

Return Value
This function return values that are as follows −

if Return value < 0 then it indicates str1 is less than str2 in lexalogical order.

if Return value > 0 then it indicates str1 is greater than str2 in lexalogical order.

if Return value = 0 then it indicates str1 is equal to str2 in lexalogical order.

Description
The C library function int strncmp(const char *str1, const char *str2, size_t n) compares at most the first n bytes of str1 and str2.
*/

#include <stdio.h>
#include <string.h>

void compare(char* str1, char* str2, int n)
{
   int ret = strncmp(str1, str2, n);

   if(ret < 0) {
      printf("\"%s\" is less than \"%s\"\n", str1, str2);
   } else if(ret > 0) {
      printf("\"%s\" is greater than \"%s\"\n", str1, str2);
   } else {
      printf("\"%s\" is equal to \"%s\"\n", str1, str2);
   }
}

int main () {
   char str1[15];
   char str2[15];

   compare("India", "Bhdia", 2);
   compare("India", "Inwow", 2);
   compare("India", "India", 2);
   compare("india", "India", 2);

   return(0);
}

/*
"India" is greater than "Bhdia"
"India" is equal to "Inwow"
"India" is equal to "India"
"india" is greater than "India"
*/
