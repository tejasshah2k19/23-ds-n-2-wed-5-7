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
    if (f == 0 && r == SIZE - 1)
    {
        printf("\nQ is Full");
    }
    else if (r == f - 1)
    {
        printf("\nQ is Full");
    }
    else
    {
        if (r == SIZE - 1)
        {
            r = 0;
        }
        else
        {
            r++;
        }
        if (f == -1)
        {
            f = 0; // first insertion
        }
        queue[r] = num;
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
        else if (f == SIZE - 1)
        {
            f = 0;
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

        if (r >= f)
        {
            for (i = f; i <= r; i++)
            {
                printf("  %d", queue[i]);
            }
        }
        else
        {

            for (i = f; i <= SIZE - 1; i++)
            {
                printf("  %d", queue[i]);
            }

            for (i = 0; i <= r; i++)
            {
                printf("  %d", queue[i]);
            }
        }
    }
}
