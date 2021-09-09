#include <stdio.h>
#include <stdlib.h>

int random(int a)
{
    int i;
    int ran = rand();
    int num = (ran % (a + 1));
    return num;
}

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
    func(10);
    return 0;
}
