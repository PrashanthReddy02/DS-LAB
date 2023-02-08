#include <stdio.h>
#include <stdlib.h>
void insert_begin(); // function declarations
void insert_end();
void insert_random();
void delete_begin();
void delete_end();
void delete_random();
void display();
void main()
{
    while (1)
    {
        int choice;
        printf("enter the choice 1.insert at begin 2. insert at end 3. insert at random 4. delete from begin 5.delete from end 6. delete from random 7. display 8.exit\n");
        scanf("%d", &choice); // reads the choice from the user
        switch (choice)       // selects alternative out of many alternatives
        {
        case 1:
            insert_begin();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_random();
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_random();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
}
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insert_begin() // function for insertion at beginning
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("unable to insert\n");
    }
    else
    {
        int x;
        printf("enter the data to be inserted\n");
        scanf("%d", &x);
        ptr->data = x;
        ptr->next = head;
        head = ptr;
    }
}
void insert_end() // function for insertion at end
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("unable to insert\n");
    }
    else
    {
        temp = head;
        int x;
        printf("enter the data to be inserted:\n");
        scanf("%d", &x);
        ptr->data = x;
        ptr->next = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}
void insert_random() // function for insertion at random location
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("unable to insert\n");
    }
    else
    {
        temp = head;
        int pos;
        int i = 1;
        printf("enter the position : ");
        scanf("%d", &pos);
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        int x;
        printf("enter the data to be inserted\n");
        scanf("%d", &x);
        ptr->data = x;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void delete_begin() // function for deletion from beginning
{
    struct node *temp;
    temp = head;
    printf("the deleted value is %d\n", temp->data);
    head = head->next;
    free(temp);
}
void delete_end() // function for deletion from end
{
    struct node *temp, *prevnode;
    temp = head;
    while (temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }
    printf("the deleted value is %d\n", temp->data);
    prevnode->next = NULL;
    free(temp);
}
void delete_random() // function for deletion from random location
{
    struct node *temp, *nextnode;
    temp = head;
    int pos;
    int i = 1;
    printf("enter the position : ");
    scanf("%d", &pos);
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    printf("the deleted value is %d\n", nextnode->data);
    temp->next = nextnode->next;
    free(nextnode);
}
void display() // function for displaying the elements of he linkedlist
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
    }
}
