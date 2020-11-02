#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int digits(long long n)
{
	int k=0;
	while(n>0)
	{
	    k++;
	    n=n/10;
	}
	return k;
}

void kaprekarNumbers(int p, int q)
{
    long long i, sq, lnum, n, rnum;
    int d, sqd, c=0;
    for(i=p;i<=q;i++)
    {
        n=i;
        if(n==1)
        {
            c++;
            printf("1 ");
            continue;
        }
        d=digits(n);
        sq = i*i;
        sqd = digits(sq);
        //	printf("num=%d, d=%d, sq=%ld, sqd=%d\n",n,d,sq,sqd);
        if(sqd == 2*d || sqd==((2*d)-1))
        {
            rnum = sq % (long long)pow(10,d);
            lnum = sq / pow(10,d);
            if((lnum+rnum)==n)
            {
                c++;
                printf("%ld ",n);
            }
        }
    }
    if(!c)
    printf("INVALID RANGE");
    // printf("\nAbove are the Kaprekar's numbers in the range %d-%d.\n",p,q);
}

int main()
{
    int p,q;
    printf("Enter lower range: ");
    scanf("%d",&p);
    printf("Enter upper range: ");
    scanf("%d",&q);

    kaprekarNumbers(p, q);

    return 0;
}
