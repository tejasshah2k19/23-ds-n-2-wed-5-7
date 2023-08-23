#include <stdio.h>
#define SIZE 5
int queue[SIZE];

int f = -1;
int r = -1;

int isEmpty()
{
    return f == -1; // 1 0
}
void insert(int num)
{
    if (r == SIZE - 1)
    {
        printf("\nQ is Full");
    }
    else
    {
        r++;
        queue[r] = num;
        if (isEmpty())
            f = 0;
    }
}

void remove()
{
    if (isEmpty())
    {
        printf("\nQ is Empty");
    }
    else
    {
        printf("\n%d deleted", queue[f]);
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f++;
        }
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQ is Empty");
    }
    else
    {
        printf("\nElements in the Queue\n");
        for (i = f; i <= r; i++)
        {
            printf("  %d", queue[i]);
        }
    }
}
