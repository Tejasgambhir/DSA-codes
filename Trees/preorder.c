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
void preOrder(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}
void postOrder(struct node * root){
    if(root!= NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }

}
void InOrder(struct node * root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }

}

int main()
{
    struct node * p1 =CreatingNode(5);
    struct node * p2 =CreatingNode(8);
    struct node * p3 =CreatingNode(9);
    struct node * p4 =CreatingNode(4);
    struct node * p5 =CreatingNode(6);

    p1->left =p2;
    p1->right = p3;
    p2->left =p4;
    p2->right =p5;

    preOrder(p1);
    printf("\n");
    postOrder(p1);
    printf("\n");
    InOrder(p1);
    return 0;
}