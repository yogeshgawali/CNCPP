/*
C library function - strncat()

Declaration - char *strncat(char *dest, const char *src, size_t n)

Parameters
dest − This is pointer to the destination array, which should contain a C string,
       and should be large enough to contain the concatenated resulting string
       which includes the additional null-character.
src  − This is the string to be appended.
n    − This is the maximum number of characters to be appended.

Return Value
This function returns a pointer to the resulting string dest.

Description
The C library function appends the string pointed to by src to the end of the
string pointed to by dest up to n characters long.
*/

#include <stdio.h>
#include <string.h>

int main () {
   char src[50], dest[50];

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");

   strncat(dest, src, 15);

   printf("Final destination string : |%s|", dest);

   return(0);
}

/*
Final destination string : |This is destinationThis is source|
*/
