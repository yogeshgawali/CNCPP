/* memchr example */
#include <stdio.h>
#include <string.h>

void* mem_char(char* st, char c, int len)
{
    int i=0;
    while(st[i] != '\0')
    {
        if(st[i] == c)
            return st+i;
        i++;
    }
    return NULL;
}

int main ()
{
    char * pch;
    char str[] = "Example string";

    //pch = (char*) memchr (str, 'p', strlen(str));

    pch = (char*) mem_char (str, 'p', strlen(str));

    if (pch!=NULL)
        printf ("'p' found at position %d.\n", pch-str+1);
    else
        printf ("'p' not found.\n");

    pch = (char*) mem_char (str, 'z', strlen(str));
    if (pch!=NULL)
        printf ("'p' found at position %d.\n", pch-str+1);
    else
        printf ("'p' not found.\n");

    return 0;
}
