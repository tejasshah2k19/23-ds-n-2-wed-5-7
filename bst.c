#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int num)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct node *addNode(struct node *root, int num) // root:90 , num:300 | root:120,num:300 | root:null num 300
{
    if (root == NULL)
    {
        root = createNode(num);
        return root;
    }
    else
    {
        if (num > root->data)
        {
            // right
            root->right = addNode(root->right, num); // NULL,120
            // 90->right = addNode(120,300);
            // 120->right = addNode(NULL,300);
        }
        else if (num < root->data)
        {
            root->left = addNode(root->left, num);
        }
        return root; // 2 1
    }
}

void inOrder(struct node *root)
{
    // left
    if (root != NULL)
    {

        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct node *root)
{
    // left
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    // left
    if (root != NULL)
    {

        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{

    int i;
    int ans;
    int num;
    int size;
    struct node *root = NULL;
    struct node *tmp = NULL;

    printf("\nHow many nodes you want to create!!");
    scanf("%d", &size);
    for (i = 1; i <= size; i++)
    {
        printf("\nEnter number");
        scanf("%d", &num);         // 90  120    50   100 150   40 70
        root = addNode(root, num); // 90,300
    }

    // printf("\n%d %d %d %d %d %d %d", root->data, root->left->data, root->right->data, root->left->left->data, root->left->right->data, root->right->left->data, root->right->right->data);

    // tree travesal

    // inOrder   left-root-right
    // preOrder  root-left-rigt
    // postOrder left-right-root
    inOrder(root);
    ans = searchData(root, 2500); // 1 - 0

    return 0;
}