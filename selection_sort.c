#include <stdio.h>
#define SIZE 5

int a[SIZE] = {10, 9, 5, 11, 76};

void display()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d", a[i]);
    }
}

void selectionSort()
{
    int i, j, tmp, min;
    int count = 0;

    for (i = 0; i < SIZE - 1; i++)
    {
        min = i;
        for (j = i + 1; j < SIZE; j++)
        {
            //
            if (a[min] > a[j])
            {
                min = j;
            }
            count++;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }

    printf("\n count = %d", count);
}
int main()
{
    printf("\nArray Before Sort\n");
    display();
    selectionSort();

    printf("\nArray After Sort\n");
    display();

    return 0;
}