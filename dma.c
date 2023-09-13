#include <stdio.h>
#include <stdlib.h>

int add()
{
    return 12 + 22;
}
struct student
{
    char name[30];
    int maths, sci;
};

int main()
{

    int *p = (int *)malloc(20);
    int *q = (int *)calloc(3, 16);
    struct student *s;
    s = (struct student *)malloc(sizeof(struct student));
    // s->maths

    return 0;
}
