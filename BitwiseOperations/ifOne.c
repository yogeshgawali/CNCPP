/*
 * C Program to check if all the bits of a given integer is one(1)
 */
#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int num = 0, count = 0, n = 0, i = 0;

	printf ("\nEnter the number : ");
	scanf ("%d", &num);
	n = num;
	if (num == 0)
	{
		printf ("\nFALSE : ALL BITS ARE NOT SET\n");
		exit (0);
	}
	while (n)
	{
		count ++;
		n = n >> 1;
	}
	for (i = 0; i < count; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			continue;
		}
		else
		{
			printf ("\nFALSE : ALL BITS ARE NOT SET\n");
			exit (0);
		}
	}
	printf ("\nTRUE : ALL BITS ARE SET\n");
	return 0;
}
