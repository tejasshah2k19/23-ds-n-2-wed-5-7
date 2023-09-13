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
int main()
{
    addNode(10);
    addNode(20);
    addNode(30);
    display();
    return 0;
}
