#include<stdio.h>

int isPalindrome(char *str)
{
    int i, j;
    i = 0;
    j = strlen(str) - 1;
    while(i<j)
    {
        if(str[i] != str[j])
        {
            printf("String is not palindrome");
            return 0;
        }
        i++;
        j--;
    }
    printf("String is Palindrome..!\n");
    return 1;
}

int main()
{
    char inputStr[100];
    printf("Enter string to test:\n");
    scanf("%s", inputStr);

    isPalindrome(inputStr);

    return 0;
}
