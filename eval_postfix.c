#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void push();//function declaration for push
int pop();//function declaration for pop
void display();//function declaration for display
int top = -1;
int ch;
char stack[25];
void push(int ele)//function for push
{
    if (top == 24)
        printf("overflow\n");
    else
    {
        top++;
        stack[top] = ele;
    }
}
int pop()//function for pop
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
void display()//function for display
{
    printf("stack is:\n");
    for (int i = 0; i <= top; i++)
        printf("|%d", stack[i]);
}
void main()//main function
{
    char postfix[25] = {'\0'};
    char ele;
    int i, num1, num2, ans;
    printf("\nenter the postfix expression:");
    scanf("%s", postfix);//reads the expression from the user
    printf("the postfix expression entered is:%s\n", postfix);
    i = 0;
    while (i <= strlen(postfix) - 1)//strlen means lenth of the string
    {
        ele = postfix[i];
        if (isdigit(ele))
            push(ele - '0');
        else
        {
            num1 = pop();//pops the top element of the stack
            num2 = pop();
            switch (ele)
            {
            case '$':
                ans = pow(num2, num1);//case for power
                break;
            case '/':
                ans = num2 / num1;//case for division
                break;
            case '*':
                ans = num2 * num1;//case for multiplication 
                break;
            case '+':
                ans = num2 + num1;//case for addition
                break;
            case '-':
                ans = num2 - num1;//case for subtraction 
                break;
            }
            push(ans);//pushes the answer into the stack
        }
        display();//displays the stack elements 
        i++;
    }
    printf("\nans=%d\n", pop());//displays the answer
}
