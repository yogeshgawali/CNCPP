#include<stdio.h>

//1

int main()
{
    int i = 1;
    printf("%d %d %d %d %d\n", i++, ++i, i, ++i, i++);
    return 0;
}


//2
/*
int main()
{
    int i = 1;
    printf("%d\n", i++);
    printf("%d\n", ++i);
    printf("%d\n", i);
    printf("%d\n", ++i);
    printf("%d\n", i++);
    return 0;
}
*/

/*
output: 1
exp: i++
out: 1 garbage

exp: i++, ++i
out: 2 3 17 10687408 16

exp: i++, ++i, i
out: 2 3 3 1381296 16

exp: i++, ++i, i, ++i
out: 3 4 4 4 35

exp: i++, ++i, i, ++i, i++
out: 4 5 5 5 1

output:2
1
3
3
4
4

*/
