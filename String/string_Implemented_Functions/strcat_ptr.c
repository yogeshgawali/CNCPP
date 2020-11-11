/* strcat example */
#include <stdio.h>
#include <string.h>

char* string_concat(char* a, char* b)
{
    int i, len1, len2;
    len1 = strlen(a);
    len2 = strlen(b);

    for(i=0; i<len2; i++)
    {
        a[len1+i] = b[i];
    }
    a[len1+i] = '\0';

    return a;

}
int main ()
{
  char* str, str1[]="these ", str2[]="strings ", str3[]="are ", str4[]="concatenated.";
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);
  printf("str3: %s\n", str3);
  printf("str4: %s\n", str4);

  str = (char*)malloc(80*sizeof(char));
  memset(str, 0, 80);
  printf("str: %s\n", str);

  str =  string_concat(str, str1);
  printf("str after concat with str1: %s\n", str);

  str =  string_concat(str, str2);
  printf("str after concat with str2: %s\n", str);

  str =  string_concat(str, str3);
  printf("str after concat with str3: %s\n", str);

  str =  string_concat(str, str4);
  printf("str after concat with str4: %s\n", str);

  return 0;
}
