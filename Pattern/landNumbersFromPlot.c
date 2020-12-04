#include<stdio.h>

#define MAX_SIZE 8
char plot[MAX_SIZE][MAX_SIZE];
int row, col;
void modifyFunction();
void changeFunction(char ,int ,int);

int main()
{
    char plot[MAX_SIZE][MAX_SIZE];
    int i, j;

    printf("Enter rows and column: \n");
    scanf("%d %d", &row, &col);
    printf("==========\n");
    printf("Enter plot: \n");
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf(" %c", &plot[i][j]);
    printf("==========\n");
    printf("Plot before modification: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%c", plot[i][j]);
        printf("\n");
    }
    modifyFunction();
    printf("==========\n");
    printf("Plot after modification: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%c", plot[i][j]);
        printf("\n");
    }
    printf("==========\n");
    return 0;
}


void modifyFunction(int i, int j)
{
    char nc='A';
    printf("In modification function\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(plot[i][j]=='@')
            {
                printf("Calling change.\n");
                changeFunction(nc, i, j);
                nc++;
            }
        }
    }
    printf("Exiting modification function\n");
}

void changeFunction(char c, int i, int j)
{
    printf("------------\n");
    plot[i][j]=c;
    printf("i=%d j=%d a[i][j]=%c\n", i, j, plot[i][j]);
    if(j-1>=0 && plot[i][j-1]=='@')
        changeFunction(c, i, j-1);
    if((j+1)<col && plot[i][j+1]=='@')
        changeFunction(c, i, j+1);
    if((i+1)<row && plot[i+1][j]=='@')
        changeFunction(c, i+1, j);
    return;
}
