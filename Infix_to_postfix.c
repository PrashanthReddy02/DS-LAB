/*C program to convert an infix expression to postfix*/
#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x) //function for pushing the elements into the stack
{
stack[++top]=x;
}
char pop() //function for popping the top element of the stack
{
if(top==-1)
return 1;
else
return stack[top--];
}
int priority(char x) //function to assign the priority value of the signs
{
if(x=='(')
return  0;
if(x=='+'||x=='-')
return 1;
if(x=='*'||x=='/')
return 2;
}
int main()
{
char exp[20];
char *e;
char x;
printf("enter the expression:\n");
scanf("%s",exp);
e=exp;
while(*e!='\0')
{
if(isalnum(*e)) //alnum means alpha numerical
printf("%c",*e);
else if(*e=='(')
push(*e);
else if(*e==')')
{
while((x=pop(1))!='(')
printf("%c",x);
}
else
{
while(priority(stack[top])>=priority(*e))
printf("%c",pop());
push(*e);
}
e++;
}
while(top!=-1)
printf("%c",pop());
}
