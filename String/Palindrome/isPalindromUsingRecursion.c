#include<stdio.h>

int isPalindrome(char word[], int index)
{
    int len = strlen(word) - (index + 1);
    if (word[index] == word[len])
    {
        if (index + 1 == len || index == len)
        {
            printf("The entered word is a palindrome\n");
            return 1;
        }
        isPalindrome(word, index + 1);
    }
    else
    {
        printf("The entered word is not a palindrome\n");
        return 0;
    }
}

int main()
{
    char inputStr[100];
    printf("Enter string to test:\n");
    scanf("%s", inputStr);

    isPalindrome(inputStr, 0);

    return 0;
}
