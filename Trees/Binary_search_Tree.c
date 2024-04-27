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
    if(root!= NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }

}
//       8
//      / \
//     5   9
//    /\
//   4  6

int isBST(struct node*root){
    static struct node*prev =NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev =root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct node*search(struct node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
struct node*search_iter(struct node*root,int key){
    while(root!=NULL){
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        root =root->left;
    }
    else{
        root =root->right;
    }
    }
    return NULL;
}
void insert(struct node*root,int key){
    struct node*prev =NULL;
    while(root!=NULL){
        prev =root;
        if(key == root->data){
            printf("cannot insert");
            return ;
        }
        else if(key<root->data){
            root =root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new =CreatingNode(key);
    if (key<prev->data)
    {
        prev->left =new;
    }
    else{
        prev->right =new;
    }
    
}
struct node* deletion(struct node*root,int key){
    struct node*prev =NULL;
    struct node*head = root;
    while(root!=NULL){
        
        if(key == root->data){
            break;
        }
        else if(key<root->data){
            prev =root;
            root =root->left;
        }
        else{
            prev=root;
            root = root->right;
        }
        
    }
    if(key>prev->data){
        prev->right =NULL;
    }
    else{
        prev->left =NULL;
    }
    return head;
}
int main()
{
    struct node * p1 =CreatingNode(8);
    struct node * p2 =CreatingNode(5);
    struct node * p3 =CreatingNode(9);
    struct node * p4 =CreatingNode(4);
    struct node * p5 =CreatingNode(6);

    p1->left =p2;
    p1->right = p3;
    p2->left =p4;
    p2->right =p5;

    // preOrder(p1);
    // printf("\n");
    // postOrder(p1);
    InOrder(p1);
    // printf("%d",isBST(p1));
    // struct node*root =search_iter(p1,4);
    printf("\n");
    // if(root!=NULL){
    //     printf(" we found  %d",root->data);
    // }
    // else{
    //     printf("%d is not in the list",4);
    // }
    // insert(p1,10);
    // printf("%d\n",p1->right->right->data);
    p1 = deletion(p1,9);
    InOrder(p1);
    return 0;
}