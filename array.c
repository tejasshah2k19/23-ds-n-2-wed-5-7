#include <stdio.h>
#define SIZE 5

int a[SIZE]; // 5 -> a[0] a[1] a[2] a[3] a[4]
             //       200  202

void insert(int data, int location)
{
    int i;
    int index = location - 1; // insert
    for (i = SIZE - 1; i > index; i--)
    {
        a[i] = a[i - 1];
    }
    a[index] = data;
}
void display()
{
}
int main()
{

    return 0;
}

// 50  : 0
// 10  : 1
// 20  : 2
// 30  : 3

// 50,1 -> 50data , 1 location
