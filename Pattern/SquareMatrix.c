#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int c = 2*n-1,x,k;
    for(int i=1;i<=c;i++)
    {
	    x=n;
	    if(i<(c/2+1))
		   k=i;
	    else
		   k=c-i+1;
	    for(int j=1;j<=c;j++)
	    {
		   if(j<k)
		   {
			  printf("%d ",x);
			  x--;
		   }
		   if(j>=k && j<=(c-k)+1)
		   {
			   printf("%d ",x);
		   }
		   if(j>(c-k)+1)
		   {
			   x++;
			   printf("%d ",x);
		   }
	    }
	    printf("\n");
    }
    return 0;
}

/*
 *input:2
 *output:
 *2 2 2
 *2 1 2
 *2 2 2
 *
 *input:3
 *output:
 *3 3 3 3 3
 *3 2 2 2 3
 *3 2 1 2 3
 *3 2 2 2 3
 *3 3 3 3 3
 *
 *inout:4
 *output:
 *4 4 4 4 4 4 4
 *4 3 3 3 3 3 4
 *4 3 2 2 2 3 4
 *4 3 2 1 2 3 4
 *4 3 2 2 2 3 4
 *4 3 3 3 3 3 4
 *4 4 4 4 4 4 4
 *
 * */

