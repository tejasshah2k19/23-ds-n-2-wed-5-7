#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int a[SIZE] = {33, 44, 55, 66, 77}; // 150 250  O(n)  -> N time {SIZE}
int main()
{
    int min = 0;
    int max = SIZE - 1;
    int mid;
    int isFound = 0;
    int search;

    printf("\nEnter Search Number");
    scanf("%d", &search);

    while (min <= max)
    {
        mid = (min + max) / 2;
        // 2 // 0+9 = 9 / 2 => 4

        if (a[mid] == search)
        {
            isFound = 1;
            break;
        }
        else if (search > a[mid])
        {
            // right
            min = mid + 1;
        }
        else
        {
            // left
            max = mid - 1;
        }
    }

    isFound == 1 ? printf("\n%d Found", search) : printf("\n%d Not found ", search);
}