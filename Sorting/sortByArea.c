#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float area(int a, int b, int c)
{
    float p, are=0.0f, af=(float)a, bf=(float)b, cf=(float)c;
    p=(af+bf+cf)/2.0f;
    are = p*(p-af)*(p-bf)*(p-cf);
    return are;
}
void sort_by_area(triangle* tr, int n) {
	int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            triangle t;
            float ai,aj;
            ai=area(tr[i].a, tr[i].b, tr[i].c);
            aj=area(tr[j].a, tr[j].b, tr[j].c);
            if(ai>aj)
            {
                t=tr[i];
                tr[i]=tr[j];
                tr[j]=t;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

/*
input
3
7 24 25
5 12 13
3 4 5

output
3 4 5
5 12 13
7 24 25
*/
