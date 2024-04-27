#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node* CreatingNode(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data =data;
    n->left =NULL;
    n->right =NULL;
    return n;
}
int main()
{
    struct node * p1 =CreatingNode(5);
    struct node * p2 =CreatingNode(8);
    struct node * p3 =CreatingNode(9);
    struct node * p4 =CreatingNode(4);

    p1->left =p2;
    p1->right = p3;
    p2->left =p4;


    return 0;
}