#include <stdio.h>
#include <stdlib.h>
/*

    class Node {
        int data;
        Node left,right;
    }
*/
struct node
{
    int data;
    struct node *left, *right; // 1) dma -> malloc
};

int main(int argc, char const *argv[])
{

    struct node *root = NULL; // head

    root = (struct node *)malloc(sizeof(struct node));
    root->data = 30;
    root->left = NULL;
    root->right = NULL;

    struct node *tmp1 = (struct node *)malloc(sizeof(struct node));
    tmp1->data = 10;
    tmp1->left = NULL;
    tmp1->right = NULL;

    root->left = tmp1;

    printf("\n%d %d", root->data, root->left->data);

    return 0;
}
