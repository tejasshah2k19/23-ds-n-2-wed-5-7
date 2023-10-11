#include <stdio.h>
// i as global
// int i=1;

// argument / parameter

//

void table(int num, int i)
{

    printf("\n%d * %d = %d ", num, i, num * i); // 1
                                                // 2 2
    if (i != 10)
        table(num, i + 1);
}

int sumOfDigits(int num)
{ // 1257 => 1257/10 %10 7+5+2+1 125
    if (num != 0)
        return num % 10 + sumOfDigits(num / 10);
    else
        return 0;
}
int main()
{
    int ans;
    table(10, 1);

    ans = sumOfDigits(1257); // 1+2+5+7
    printf("\nAns = %d", ans);
    return 0;
}