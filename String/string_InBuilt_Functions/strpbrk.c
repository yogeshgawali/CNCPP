/*
C library function - strpbrk()

Declaration - char *strpbrk(const char *str1, const char *str2)

Parameters
str1 − This is the C string to be scanned.
str2 − This is the C string containing the characters to match.

Return Value
This function returns a pointer to the character in str1 that matches
one of the characters in str2, or NULL if no such character is found.

Description
This function finds the first character in the string str1 that matches
any character specified in str2. This does not include the terminating null-characters.
*/

#include <stdio.h>
#include <string.h>

int main () {
   const char str1[] = "abcde2fghi3jk4l";
   char str2[] = "34";
   char *ret;

   ret = strpbrk(str1, str2);
   if(ret) {
      printf("First matching character: %c\n", *ret);
   } else {
      printf("Character not found\n");
   }

   strcpy(str2, "54");
   ret = strpbrk(str1, str2);
   if(ret) {
      printf("First matching character: %c\n", *ret);
   } else {
      printf("Character not found\n");
   }

   strcpy(str2, "55");
   ret = strpbrk(str1, str2);
   if(ret) {
      printf("First matching character: %c\n", *ret);
   } else {
      printf("Character not found\n");
   }

   return(0);
}

/*
First matching character: 3
First matching character: 4
Character not found
*/
