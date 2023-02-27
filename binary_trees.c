#include <stdio.h> //header files
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create() // function for creating a children node
{
    int x;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter the data (-1 for no node)\n");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    ptr->data = x;
    printf("enter the left child of %d:\n", x);
    ptr->left = create();
    printf("enter the right child of %d:\n", x);
    ptr->right = create();
    return ptr;
}
void preorder(struct node *root) // function for postoreder traversal
{
    if (root == 0)
    {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root) // function for inorder traversal
{
    if (root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);

    inorder(root->right);
}
void postorder(struct node *root) // function for postorder traversal
{
    if (root == 0)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}
void main() // main function
{
    struct node *root;
    root = NULL;
    root = create();
    printf("inorder traversal is :\n");
    inorder(root);
    printf("\n");
    printf("preorder traversal is :\n");
    preorder(root);
    printf("\n");
    printf("postorder traversal is :\n");
    postorder(root);
    printf("\n");
}
