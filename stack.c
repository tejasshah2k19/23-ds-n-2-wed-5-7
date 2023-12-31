#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int num)
{
    if (top == SIZE - 1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

int pop()
{
    int num;
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY");
        return -1;
    }
    else
    {
        num = stack[top];
        printf("\n %d POP", num);
        top--;
        return num;
    }
}

void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
}

void peep(int location)
{
    int index;
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY");
    }
    else
    {
        index = top - location + 1;
        if (index < 0)
        {
            printf("\nInvalid Location PTA");
        }
        else
        {
            printf("\n%d ", stack[index]);
        }
    }
}

int main()
{
    int choice, num, location;
    while (-1) // 0 is false
    {
        printf("\n1 For PUSH\n2 For POP\n3 For Display\n4 For Peep\n0 For Exit\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nEnter location");
            scanf("%d", &location);
            peep(location);
        case 0:
            exit(0);
        default:
            printf("\nInvalid Choice PTA");
            break;
        }
    }
    return 0;
}
