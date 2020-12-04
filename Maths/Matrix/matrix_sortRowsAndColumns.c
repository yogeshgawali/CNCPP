/*
 * C program to accept a matrics of order MxN and sort all rows of the
 * matrix in ascending order and all columns in descending order
 */
#include <stdio.h>

void main()
{
    static int array1[10][10], array2[10][10];
    int i, j, k, a, m, n;

    printf("Enter the order of the matrix \n");
    scanf("%d %d", &m, &n);
    printf("Enter co-efficients of the matrix \n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &array1[i][j]);
            array2[i][j] = array1[i][j];
        }
    }
    printf("The given matrix is \n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
                printf(" %d", array1[i][j]);
        }
        printf("\n");
    }
    printf("After arranging rows in ascending order\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            for (k =(j + 1); k < n; ++k)
            {
                if (array1[i][j] > array1[i][k])
                {
                    a = array1[i][j];
                    array1[i][j] = array1[i][k];
                    array1[i][k] = a;
                }
            }
        }
    }
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf(" %d", array1[i][j]);
        }
        printf("\n");
    }
    printf("After arranging the columns in descending order \n");
    for (j = 0; j < n; ++j)
    {
        for (i = 0; i < m; ++i)
        {
            for (k = i + 1; k < m; ++k)
            {
                if (array2[i][j] < array2[k][j])
                {
                    a = array2[i][j];
                    array2[i][j] = array2[k][j];
                    array2[k][j] = a;
                }
            }
        }
    }
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf(" %d", array2[i][j]);
        }
        printf("\n");
    }
}


/*
Enter the order of the matrix
5 5
Enter co-efficients of the matrix
5 3 87 12 22
47 04 78 83 90
1 56 32 64 12
54 62 47 10 40
11 99 44 55 66
The given matrix is
 5 3 87 12 22
 47 4 78 83 90
 1 56 32 64 12
 54 62 47 10 40
 11 99 44 55 66
After arranging rows in ascending order
 3 5 12 22 87
 4 47 78 83 90
 1 12 32 56 64
 10 40 47 54 62
 11 44 55 66 99
After arranging the columns in descending order
 54 99 87 83 90
 47 62 78 64 66
 11 56 47 55 40
 5 4 44 12 22
 1 3 32 10 12
 */
