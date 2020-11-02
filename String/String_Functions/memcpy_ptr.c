#include <stdio.h>

int main ()
{
    char *str, myname[] = "Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination.";
    int len, i=0;
    len = strlen(myname);

    printf("Original string is: %s\n", myname);
    printf("Length of string  : %d\n", len);

    str = (char*)malloc(500*sizeof(char));
    memset(str, '#', 500);

    while(myname[i] != '\0')
    {
        str[i] = myname[i];
        i++;
    }

    printf("Original string: %s\n", myname );
    printf("Copied string  : %s\n", str );

    str[i] = '\0';
    printf("Original string: %s\n", myname );
    printf("Copied string  : %s\n", str );

    free(str);
    return 0;
}
