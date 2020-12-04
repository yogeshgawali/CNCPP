/*
 * C program to interchange any 2 tows and columns
 */

#include <stdio.h>

int main()
{
    int array[10][10], array1[10][10];
    int i, j, m, n, x, y;

    printf("Enter the order of the matrix\n");
    scanf("%d %d", &m, &n);
    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d ", &array[i][j]);
        }
    }
    printf("The input matrix is:\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
                printf(" %d", array1[i][j]);
        }
        printf("\n");
    }

    //Interchanging rows
    printf("Enter 2 row indexes to interchange: \n");
    scanf("%d %d", &x, &y);

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(j==x)
                array1[i][j] = array[i][y];
            else if(j==y)
                array1[i][j] = array[i][x];
            else
                array1[i][j] = array[i][j];
        }
    }
    printf("Array after interchanging rows %d and %d is: \n", x, y);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", array1[i][j]);
        printf("\n");
    }
    printf("\n");

    //interchanging columns
    printf("Enter 2 column indexes to interchange: \n");
    scanf("%d %d", &x, &y);

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==x)
                array1[i][j] = array[y][j];
            else if(j==y)
                array1[i][j] = array[x][j];
            else
                array1[i][j] = array[i][j];
        }
    }
    printf("Array after interchanging rows %d and %d is: \n", x, y);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", array1[i][j]);
        printf("\n");
    }
    return 0;
}
