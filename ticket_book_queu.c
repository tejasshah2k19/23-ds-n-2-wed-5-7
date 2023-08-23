#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

struct user
{
    char name[30];
    int qty;
    int contact;
};

int f = -1, r = -1;
struct user queue[SIZE];
int isEmpty()
{
    return f == -1;
}
void insert(struct user u) // int num
{
    if (r == SIZE - 1)
    {
        printf("\nQ is Full");
    }
    else
    {
        r++;
        queue[r] = u;
        if (isEmpty())
            f = 0;
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
            printf("\n  %s %d  %d", queue[i].name, queue[i].contact, queue[i].qty);
        }
    }
}

int main()
{

    int choice;
    char tmpname[30];
    int tmpcontact;
    while (1)
    {

        printf("\n1 For Buy Ticket\n2 For View Ticket\n3 For List tickets\n4 For Exit\nEnter Choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Name and contact number");
            scanf("%s%d", &tmpname, &tmpcontact);
            struct user x;
            strcpy(x.name, tmpname);
            x.contact = tmpcontact;
            x.qty = 1;
            insert(x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        } // switch
    }     // while
    return 0;
}