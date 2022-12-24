#include <stdio.h>
int fact(int);//function declarion
int main()
{
    int n, res;
    printf("Enter the number:\n");
    scanf("%d", &n);//reads the number from the user
    res = fact(n);
    printf("the factorial of %d is %d\n", n, res);
    return 0;
}
int fact(int n)//function for factorial
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        return n * fact(n - 1);
    }
}
