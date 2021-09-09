#include <stdio.h>

int func(int n)
{
    int i;
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        i = random(n - 1);
        printf("this\n");
        return func(i) + func(n - 1 - i);
    }
}

int main()
{
    func(4);
    return 0;
}
