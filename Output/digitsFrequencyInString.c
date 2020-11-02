#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *s = (char*)malloc(100 * sizeof(char));
	int arr[10], x;
	for(int i=0;i<10;i++)
		arr[i]=0;
	printf("Enter string of alphabets and numerals:");
	scanf("%s",s);
	int l = strlen(s);
	printf("Input string is : %s\n",s);
	for(int i=0;i<l;i++)
	{
		x = *(s+i)-48;
		if(x<=9)
			arr[x]++;
	}
	for(int i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");
}


