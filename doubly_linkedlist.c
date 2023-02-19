#include <stdio.h>
#include <stdlib.h>
void insert_begin(); // header files
void insert_end();
void insert_random();
void delete_begin();
void delete_end();
void delete_random();
void display();
void main() // main function
{
    while (1)
    {
        int choice;
        printf("enter the choice 1.insert at beginning 2.insert at end 3.insert at random location 4.delete from beginning 5.delete from end 6.delete from random location 7.display 8.exit\n");
        scanf("%d", &choice);
        switch (choice) // selects the choice from the user
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
    struct node *next;
    struct node *prev;
    int data;
};
struct node *head;
void insert_begin() // function for insertion at beginning
{
    int x;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("not able to insert\n");
    else
    {
        printf("enter the value to be inserted\n");
        scanf("%d", &x);
        ptr->data = x;
        ptr->prev = NULL;
        ptr->next = head;
        head = ptr;
    }
}
void insert_end() // function for insertion at end
{
    int x;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    temp = head;
    if (ptr == NULL)
        printf("not able to insert\n");
    else
    {
        printf("enter the value to be inserted\n");
        scanf("%d", &x);
        ptr->data = x;
        ptr->next = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        ptr->prev = temp->next;
        temp->next = ptr;
    }
}
void insert_random() // function for insertion at random location
{
    int x, pos;
    int i = 1;
    struct node *ptr, *temp, *nextnode;
    ptr = (struct node *)malloc(sizeof(struct node));
    temp = head;
    if (ptr == NULL)
        printf("not able to insert\n");
    else
    {
        printf("enter the position after which the value has to be inserted:\n");
        scanf("%d", &pos);
        printf("enter the value to be inserted:\n");
        scanf("%d", &x);
        ptr->data = x;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        nextnode = ptr->next;
        nextnode->prev = ptr;
    }
}
void delete_begin() // function for deletion from beginning
{
    struct node *temp;
    temp = head;
    if (head == NULL)
        printf("underflow\n");
    else
    {
        printf("the deleted element is %d\n", head->data);
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
void delete_end() // function from deletion from end
{
    struct node *temp, *prevnode;
    temp = head;
    if (head == NULL)
        printf("underflow\n");
    else
    {
        while (temp->next != NULL)
        {
            prevnode = temp;
            temp = temp->next;
        }

        printf("the deleted element is %d\n", temp->data);
        prevnode->next = NULL;
        free(temp);
    }
}
void delete_random() // function for deletion from random location
{
    int pos, i = 1;
    struct node *temp, *newnode, *nextnode;
    temp = head;
    if (head == NULL)
        printf("underflow\n");
    else
    {
        printf("enter the index of node to be deleted:\n");
        scanf("%d", &pos);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        newnode = nextnode->next;
        newnode->prev = temp;
        free(nextnode);
    }
}
void display() // function for displaying the elements of the linked list
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
            printf("%d-->", temp->data);
            temp = temp->next;
        }
    }
}
