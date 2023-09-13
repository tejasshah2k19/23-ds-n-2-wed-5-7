#include <stdio.h>
#define SIZE 5

int a[SIZE] = {10, 11, 5, 11, 76};

void display()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d", a[i]);
    }
}

void insertionSort()
{
    int i, j, tmp;

    for (i = 1; i < SIZE; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > tmp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = tmp;
    }
}
int main()
{
    printf("\nArray Before Sort\n");
    display();
    insertionSort();

    printf("\nArray After Sort\n");
    display();

    return 0;
}