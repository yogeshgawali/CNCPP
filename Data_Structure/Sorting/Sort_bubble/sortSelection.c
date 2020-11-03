#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void printline(int count)
{
    int i;

    for(i = 0;i < count-1;i++)
        printf("=");

    printf("=\n");
}

void display()
{
    int i;
    printf("[");

    for(i = 0;i < MAX;i++)          // navigate through all items
        printf("%d ", intArray[i]);

    printf("]\n");
}

void selectionSort()
{
    int indexMin,i,j;

    // loop through all numbers
    for(i = 0; i < MAX-1; i++)
    {
        indexMin = i;               // set current element as minimum

        for(j = i+1;j < MAX;j++)    // check the element to be minimum
        {
            if(intArray[j] < intArray[indexMin])
                indexMin = j;
        }

        if(indexMin != i)
        {
            printf("Items swapped: [ %d, %d ]\n" , intArray[i], intArray[indexMin]);
            int temp = intArray[indexMin]; // swap the numbers
            intArray[indexMin] = intArray[i];
            intArray[i] = temp;
        }
        printf("Iteration %d#:",(i+1));
        display();
    }
}

void main()
{
    printf("Input Array: ");
    display();
    printline(50);
    selectionSort();
    printline(50);
    printf("Output Array: ");
    display();
}
