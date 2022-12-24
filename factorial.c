#include <stdio.h>
int fact(int);
int main()
{
    int n, res;
    printf("Enter the number:\n");
    scanf("%d", &n);
    res = fact(n);
    printf("the factorial of %d is %d\n", n, res);
    return 0;
}
int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        return n * fact(n - 1);
    }
}
