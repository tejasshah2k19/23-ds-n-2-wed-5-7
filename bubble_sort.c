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

void bubbleSort()
{
    int i, j, tmp;
    int count = 0;
    int abc;
    for (i = 0; i < SIZE - 1; i++) // 4
    {
        abc = 0;
        for (j = 0; j < SIZE - 1 - i; j++) // 5-1-1   j < 3  0 1 2 3
        {
            count++;
            if (a[j] > a[j + 1])
            {
                abc = 1;
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
        if (abc == 0)
        {
            break;
        }

        printf("\nPass %d:\n", i + 1);
        display();
    }
    printf("\nTOTAL EXECUTION = %d", count);
}
int main()
{
    printf("\nArray Before Sort\n");
    display();
    bubbleSort();

    printf("\nArray After Sort\n");
    display();

    return 0;
}