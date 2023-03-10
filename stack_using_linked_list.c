/*C program to implement stack using linked lists*/
#include <stdio.h>
#include <stdlib.h>
void push();    // function declaration for push
void pop();     // function declration for pop
void display(); // function declaration for display
void main()
{
    while (1)
    {
        int choice;
        printf("enter the choice 1.push 2.pop 3.display 4.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
        }
    }
}
struct node // creates a newnode ptr
{
    int val;
    struct node *next;
    struct node *ptr;
};
struct node *head;
void push() // function for pushing the elements into the stack
{

    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("not able to push the element\n");
    }
    else
    {
        printf("enter the value\n");
        scanf("%d", &val);
        if (head == NULL)
        {
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }
        printf("item pushed\n");
    }
}
void pop() // function for popping the elements from the stack
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("item popped\n");
    }
}
void display() // function for displaying the elements the present in the stack
{
    int i;
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("printing stack element\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}
