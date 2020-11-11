#include <stdio.h>
#include <string.h>

/*
C library function - strcat()

Declaration - char *strcat(char *dest, const char *src)

Parameters
dest − This is pointer to the destination array, which should contain a C string,
       and should be large enough to contain the concatenated resulting string.
src  − This is the string to be appended. This should not overlap the destination.

Return Value
This function returns a pointer to the resulting string dest.

Description
The function appends the string pointed to by src to the end of the string pointed to by dest.
*/


int main () {
   char src[50], dest[50];

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");

   strcat(dest, src);

   printf("Final destination string : |%s|", dest);

   return(0);
}

/*
Final destination string : |This is destinationThis is source|
*/
