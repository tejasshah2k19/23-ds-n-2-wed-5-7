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

int main()
{
    int choice, num;
    while (-1) // 0 is false
    {
        printf("\n1 For PUSH\n2 For POP\n3 For Display\n0 For Exit\nEnter your choice");
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
        case 0:
            exit(0);
        default:
            printf("\nInvalid Choice PTA");
            break;
        }
    }
    return 0;
}
