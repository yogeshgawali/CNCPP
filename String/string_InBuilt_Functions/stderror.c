/*
C library function - strerror()

Declaration - char *strerror(int errnum)
Parameters
errnum − This is the error number, usually errno.

Return Value
This function returns a pointer to the error string describing error errnum.

Description
The C library function char *strerror(int errnum) searches an internal array for the error number errnum and returns a pointer to an error message string. The error strings produced by strerror depend on the developing platform and compiler.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main () {
   FILE *fp;

   fp = fopen("file.txt","r");
   if( fp == NULL ) {
      printf("Error: %s\n", strerror(errno));
   }

   return(0);
}

/*
Error: No such file or directory
*/
