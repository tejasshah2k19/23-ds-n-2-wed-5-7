#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char c)
{
    if (top == SIZE - 1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    char c;
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY");
        return -1;
    }
    else
    {
        c = stack[top];
        printf("\n %c POP", c);
        top--;
        return c;
    }
}

void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("\n%c", stack[i]);
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
            printf("\n%c ", stack[index]);
        }
    }
}

int main()
{
    int choice, i, location;
    char c;
    char str[SIZE];

    while (-1) // 0 is false
    {
        printf("\n1 For PUSH\n2 For POP\n3 For Display\n4 For Peep\n0 For Exit\nEnter your choice");
        scanf("%d", &choice); // 123 -> buffer-> enter

        switch (choice)
        {
        case 1:
            printf("\nEnter String");
            fflush(stdin);
            gets(str); // r:0 o:1 y:2 a:3 l:4 \0:5 -> string termination character

            for (i = 0; str[i] != '\0'; i++)
            {                 // 0 1 2 3
                push(str[i]); // r o y a l
            }

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
