/*
C library function - strspn()

Declaration - size_t strspn(const char *str1, const char *str2)

Parameters
str1 − This is the main C string to be scanned.
str2 − This is the string containing the list of characters to match in str1.

Return Value
This function returns the number of characters in the initial segment of str1
which consist only of characters from str2.

Description
The C library function calculates the length of the initial segment of str1
which consists entirely of characters in str2.
*/

#include <stdio.h>
#include <string.h>

int main () {
   int len;
   const char str2[] = "ABCD";

   const char str11[] = "ABCDEFG019874";
   len = strspn(str11, str2);
   printf("Length of initial segment matching %d\n", len );

   const char str12[] = "BCDEFG019874";
   len = strspn(str12, str2);
   printf("Length of initial segment matching %d\n", len );

   const char str13[] = "ABDEFG019874";
   len = strspn(str13, str2);
   printf("Length of initial segment matching %d\n", len );

   return(0);
}

/*
Length of initial segment matching 4
Length of initial segment matching 3
Length of initial segment matching 3
*/
