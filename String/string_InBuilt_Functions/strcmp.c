/*
C library function - strcmp()
Description
The C library function int strcmp(const char *str1, const char *str2) compares the string pointed to, by str1 to the string pointed to by str2.

Declaration
Following is the declaration for strcmp() function.

int strcmp(const char *str1, const char *str2)
Parameters
str1 − This is the first string to be compared.

str2 − This is the second string to be compared.

Return Value
This function return values that are as follows −

if Return value < 0 then it indicates str1 is less than str2 in lexalogical order.

if Return value > 0 then it indicates str1 is greater than str2 in lexalogical order.

if Return value = 0 then it indicates str1 is equal to str2 in lexalogical order.
*/

#include <stdio.h>
#include <string.h>

void compare(char* str1, char* str2)
{
   int ret = strcmp(str1, str2);

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

   compare("India","Bharat");
   compare("India","wow");
   compare("India","India");
   compare("india","India");

   return(0);
}

/*
"India" is greater than "Bharat"
"India" is less than "wow"
"India" is equal to "India"
"india" is greater than "India"
*/
