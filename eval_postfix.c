#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void push();
int pop();
void display();
int top = -1;
int ch;
char stack[25];
void push(int ele)
{
    if (top == 24)
        printf("overflow\n");
    else
    {
        top++;
        stack[top] = ele;
    }
}
int pop()
{
    if (top == -1)
        printf("underflow\n");
    else
    {

        ch = stack[top];
        top--;
    }
    return ch;
}
void display()
{
    printf("stack is:\n");
    for (int i = 0; i <= top; i++)
        printf("|%d", stack[i]);
}
void main()
{
    char postfix[25] = {'\0'};
    char ele;
    int i, num1, num2, ans;
    printf("\nenter the postfix expression:");
    scanf("%s", postfix);
    printf("the postfix expression entered is:%s\n", postfix);
    i = 0;
    while (i <= strlen(postfix) - 1)
    {
        ele = postfix[i];
        if (isdigit(ele))
            push(ele - '0');
        else
        {
            num1 = pop();
            num2 = pop();
            switch (ele)
            {
            case '$':
                ans = pow(num2, num1);
                break;
            case '/':
                ans = num2 / num1;
                break;
            case '*':
                ans = num2 * num1;
                break;
            case '+':
                ans = num2 + num1;
                break;
            case '-':
                ans = num2 - num1;
                break;
            }
            push(ans);
        }
        display();
        i++;
    }
    printf("\nans=%d\n", pop());
}
