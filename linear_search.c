#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int a[SIZE] = {33, 44, 55, 66, 77}; // 150 250  O(n)  -> N time {SIZE}
int main()
{
    int search;
    int isFound = 0; // false
    int i;
    int count = 0;
    printf("\nEnter number that you want to search");
    scanf("%d", &search);
    for (i = 0; i < SIZE; i++)
    {
        count++;
        if (a[i] == search)
        {
            isFound = 1;
            printf("\n%d Found", search);
            break;
        }
    }
    if (isFound == 0)
    {
        printf("\n%d Not found", search);
    }
    printf("\nTotal Execution = %d", count);
    return 0;
}
// timecomplexity -> O -> worst