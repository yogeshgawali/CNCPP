/*
Arithematic Progression:

11 14 17 20 23 26 29
a a+d a+2d a+3d ....

a  - first term
an - last term
sn - sum of n terms

an = a + (n-1)d
sn = a + an

*/

#include <stdio.h>
#include <math.h>

int main()
{
     int a, d, n, i, tn;
     int sum = 0;

     printf("Enter the first term value of the A.P. series: ");
     scanf("%d", &a);
     printf("Enter the total numbers in the A.P. series: ");
     scanf("%d", &n);
     printf("Enter the common difference of A.P. series: ");
     scanf("%d", &d);
     sum = (n * (2 * a + (n - 1)* d ))/ 2;
     tn = a + (n - 1) * d;
     printf("Sum of the A.P series is: ");
     for (i = a; i <= tn; i = i + d )
     {
          if (i != tn)
               printf("%d + ", i);
          else
               printf("%d = %d ", i, sum);
     }
     return 0;
}

/*
Enter the first term value of the A.P. series: 11
Enter the total numbers in the A.P. series: 5
Enter the common difference of A.P. series: 3
Sum of the A.P series is: 11 + 14 + 17 + 20 + 23 = 85
*/
