#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *last = NULL;

void addNode(int num) // 10 20 30
{
    struct node *tmp;
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
        last = head;
    }
    else
    {

        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

void display()
{
    struct node *p;
    p = head;

    while (p != NULL)
    {
        printf(" %d", p->data); // 10 20 30
        p = p->next;
    }
}

void addBeg(int num)
{
    struct node *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->next = head;
    head = tmp;
}

void search(int key)
{
    // 10 20 30 40 50|NULL
    // key: 70
    int found = 0; // 0 -> not found
    struct node *p = head;

    while (p != NULL)
    {
        if (p->data == key)
        {
            found = 1;
            break;
        }
        p = p->next;
    }

    if (found == 1)
        printf("\nPresent");
    else
        printf("\nNotPresent");
}
void insertAtAny(int key, int num) // 30,600
{
    struct node *p;
    struct node *tmp;
    p = head;

    while (p != NULL)
    {
        if (p->data == key)
        {
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\nInvalid Key");
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = p->next;
        p->next = tmp;
    }
}

void deleteBeg()
{
    struct node *p;
    p = head;
    head = head->next;
    free(p);
}

void deleteAny(int key) // 30
{
    struct node *p, *q;
    p = head;
    while (p != NULL)
    {
        if (p->data == key)
        {
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\nInvalid Key");
    }

    else if (p == head)
    {
        deleteBeg();
    }
    else
    {
        q = head;
        while (q != NULL)
        {
            if (q->next == p)
            {
                break;
            }
            q = q->next;
        }
        q->next = p->next;
        free(p);
    }
}
int main()
{
    addNode(10);
    addNode(20);
    addNode(30);
    display();
    addBeg(-20);
    printf("\n");
    display();
    insertAtAny(20, 600);
    insertAtAny(600, 700);
    printf("\n");
    display();
    deleteBeg();
    printf("\n");
    display();

    return 0;
}

// key : 23
// search 23 ? -> present , not present
