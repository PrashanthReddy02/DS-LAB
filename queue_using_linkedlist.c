#include <stdio.h>
#include <stdlib.h>
void enqueue(); // function declaration for enqueue
void dequeue(); // function declration for dequeue
void display(); // function declaration for display
void main()
{
    while (1)
    {
        int choice;
        printf("enter the choice 1.enqueue 2.dequeue 3.display 4.exit\n");
        scanf("%d", &choice); // reads the option from the user
        switch (choice)       // selects alternative out of many alternatives
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
struct node
{
    int val;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue() // function for enqueue
{
    int val;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node)); // dynamic allocation
    if (ptr == NULL)
        printf("not able to enqueue\n");
    else
    {
        printf("enter the value to be inserted\n");
        scanf("%d", &val);
        ptr->val = val;
        ptr->next = NULL;
        if (front == 0 && rear == 0)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}
void dequeue() // function for dequeue
{
    struct node *ptr;
    ptr = front;
    if (front == 0 && rear == 0)
        printf("underflow\n");
    else
    {
        printf("the dequeued element is %d\n", front->val);
        front = front->next;
        free(ptr);
    }
}
void display() // function for display
{
    struct node *ptr;
    ptr = front;
    if (front == 0 && rear == 0)
        printf("underflow\n");
    else
    {
        while (ptr != NULL)
        {
            printf("%d|", ptr->val);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
