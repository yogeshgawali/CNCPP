#include<stdio.h>

#define MAX_SIZE 8
char plot[MAX_SIZE][MAX_SIZE];
int row, col;
void modifyFunction();
void changeFunction(char ,int ,int);
void displayPlot();

int main()
{
    int i, j;

    printf("Enter rows and column: \n");
    scanf("%d %d", &row, &col);
    printf("\n");
    printf("Enter plot: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf(" %c", &plot[i][j]);
    }
    printf("==========\n");
    printf("Plot before modification: \n");
    displayPlot();
    modifyFunction();
    printf("==========\n");
    printf("Plot after modification: \n");
    displayPlot();
    printf("==========\n");
    return 0;
}


void modifyFunction(int i, int j)
{
    char nc='A';
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(plot[i][j]=='@')
            {
                changeFunction(nc, i, j);
                nc++;
            }
        }
    }
    printf("Total land count = %d\n", nc-65);
}

void changeFunction(char c, int i, int j)
{
    plot[i][j]=c;
    if(j-1>=0 && plot[i][j-1]=='@')
        changeFunction(c, i, j-1);
    if((j+1)<col && plot[i][j+1]=='@')
        changeFunction(c, i, j+1);
    if((i+1)<row && plot[i+1][j]=='@')
        changeFunction(c, i+1, j);
    return;
}

void displayPlot()
{
    int i, j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%c", plot[i][j]);
        printf("\n");
    }
}
/*     ----input set 1
Enter rows and column:
4
4
==========
Enter plot:
@@..
..@@
@..@
..@@
==========
Plot before modification:
@@..
..@@
@..@
..@@
==========
Plot after modification:
AA..
..BB
C..B
..BB
==========
*/

/*
Enter rows and column:
7
7
==========
Enter plot:
@..@@.@
@@...@@
..@.@@@
@@@@...
.....@.
@@@..@.
.@@.@@@
==========
Plot before modification:
@..@@.@
@@...@@
..@.@@@
@@@@...
.....@.
@@@..@.
.@@.@@@
Total land count = 6
==========
Plot after modification:
A..BB.C
AA...CC
..D.CCC
DDDD...
.....E.
FFF..E.
.FF.EEE
==========
*/
