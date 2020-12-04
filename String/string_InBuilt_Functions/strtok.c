/*
C library function - strtok()

Declaration - char *strtok(char *str, const char *delim)

Parameters
str − The contents of this string are modified and broken into smaller strings (tokens).
delim − This is the C string containing the delimiters. These may vary from one call to another.

Return Value
This function returns a pointer to the first token found in the string.
A null pointer is returned if there are no tokens left to retrieve.

Description
The C library function breaks string str into a series of tokens using the delimiter delim.
*/

#include <string.h>
#include <stdio.h>

int main()
{
   char str[80] = "This function returns a pointer to the first token found in the string.";
   const char s[2] = " ";
   char *token;

   /* get the first token */
   token = strtok(str, s);

   /* walk through other tokens */
   while( token != NULL ) {
      printf( "%s\n", token );

      token = strtok(NULL, s);
   }

   return(0);
}

/*
input 0:
This is - www.tutorialspoint.com - website

output 0:
This is
 www.tutorialspoint.com
 website

input 0:
This function returns a pointer to the first token found in the string.

output 0:
This
function
returns
a
pointer
to
the
first
token
found
in
the
string.
*/
