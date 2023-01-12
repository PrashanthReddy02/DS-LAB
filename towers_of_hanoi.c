#include <stdio.h>
void towers(int, char, char, char); // function declaration
void main()
{
    int n;
    printf("enter the number of disks\n");
    scanf("%d", &n); // reads the number of disks from the user
    towers(n, 'A', 'C', 'B');
}
void towers(int n, char S, char D, char A)
{
    if (n > 0)
    {
        towers(n - 1, S, A, D);
        printf("moved %d disc from rod %c to rod %c\n", n, S, D); // prints the result
        towers(n - 1, A, S, D);
    }
}
