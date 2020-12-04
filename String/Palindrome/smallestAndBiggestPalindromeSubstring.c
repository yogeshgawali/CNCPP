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
            printf("String \"%s\" is not palindrome..!!\n", str);
            return 0;
        }
        i++;
        j--;
    }
    printf("String %s is Palindrome..!!\n", str);
    return 1;
}

void smallestAndBiggestPalindromeSubstring(char str[])
{
    const char s[2] = " ";
    char *token, *smallest, *biggest;
    int smallCount = 0, bigCount = 0, count = 0;
    /* get the first token */
    token = strtok(str, s);

    /* walk through other tokens */
    while( token != NULL )
    {
        if(isPalindrome(token))
        {
            count = strlen(token);
            if((bigCount == smallCount) && (bigCount == 0))
            {
                bigCount = count;
                smallCount = count;
                smallest = token;
                biggest = token;
            }
            else if((bigCount == smallCount) && (bigCount != 0))
            {
                if(count > bigCount)
                {
                    bigCount = count;
                    biggest = token;
                }
                else if(count < smallCount)
                {
                    smallCount = count;
                    smallest = token;
                }
            }
        }
        token = strtok(NULL, s);
    }
    printf("Biggest palindrome String is: %s\n", biggest);
    printf("Smallest palindrime string is: %s\n", smallest);
}

int main()
{
    char inputStr[100] = "This function returns aba pointer totot the abcba first token xyx found in the string.";
    //printf("Enter string to test:\n");
    //scanf("%s", inputStr);

    smallestAndBiggestPalindromeSubstring(inputStr);

    return 0;
}
