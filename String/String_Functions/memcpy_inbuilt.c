//void * memcpy ( void * destination, const void * source, size_t num );

#include <stdio.h>

int main ()
{
    char *str, myname[] = "Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination.";
    int len;
    len = strlen(myname);
    len++;                                  //compensate for '\0'

    str = (char*)malloc(len*sizeof(char));

    memcpy(str, myname, len);
    printf("Original string: %s\n", myname );
    printf("Copied string  : %s\n", str );

    memset(str, 0, len);

    memcpy(str, myname, 20);
    printf("Original string: %s\n", myname );
    printf("first 20 char  : %s\n", str );

    memset(str, 0, len);

    memcpy(str, myname+20, 20);
    printf("Original string: %s\n", myname );
    printf("random 20 char : %s\n", str );

    free(str);
    return 0;
}
