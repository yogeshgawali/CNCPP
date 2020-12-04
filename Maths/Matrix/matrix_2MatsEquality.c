#include<stdio.h>

int mata[10][10];
int matb[10][10];

int main()
{
    int ra, ca, rb, cb, i, j, flag;

    printf("Enter rows and column for matrix A: \n");
    scanf("%d %d\n", &ra, &ca);
    printf("Enter rows and column for matrix B: \n");
    scanf("%d %d\n", &rb, &cb);

    //input matrix A
    printf("Enter matrix A:\n");
    for(i=0; i<ra; i++)
    {
        for(j=0; j<ca; j++)
            scanf("%d", &mata[i][j]);
    }

    //Input matrix B
    printf("Enter matrix B:\n");
    for(i=0; i<ra; i++)
    {
        for(j=0; j<ca; j++)
            scanf("%d", &matb[i][j]);
    }

    //compare matrices
    flag = 0;
    for(i=0; i<ra; i++)
    {
        for(j=0; j<ca; j++)
        {
             if(mata[i][j] != matb[i][j])
             {
                 flag = 1;
                 break;
             }
        }
        if(flag==1)
            break;
    }
    if(flag)
        printf("Matrices are equal.\n");
    else
        printf("Matrices are not equal.\n");

    return 0;
}
