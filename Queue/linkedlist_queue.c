#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * f =NULL;
struct node * r =NULL;
void LInkedlistTraversal(struct node* ptr){
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n"); 
    
}
int isFull (struct node*n){
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct node*f){
    if(f==NULL){
        return 1;
    }
    return 0;
}
void enqueue(int val){
    struct node * n = (struct node*)malloc(sizeof(struct node));
    if(isFull(n)){
        printf("queue is full");
    }
    else{
        n->data =val;
        n->next =NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
void dequeue(){
    struct node* ptr =f;
    if (isEmpty(f))
    {
        printf("queue is empty");
    }
    else{
        f=f->next;
        free(ptr);
    }
    
}
int main()
{
    
    enqueue(20);
    enqueue(0);
    enqueue(2);
    enqueue(9);
    LInkedlistTraversal(f);
    dequeue();
    LInkedlistTraversal(f);

    return 0;
}