#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack* next;
};
void LInkedlistTraversal(struct stack* ptr){
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n"); 
    
}
int isEmpty(struct stack * top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack * top){
    struct stack *n = (struct stack*)malloc(sizeof(struct stack));
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct stack* push(struct stack * top,int val){
    if(isFull(top)){
        printf("Stack overflow");
    }
    else{
        struct stack * n =  (struct stack*)malloc(sizeof(struct stack));
        n->data=val;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct stack ** top){
    if(isEmpty((*top))){
        printf("Stack underflow");
    }
    else{
        struct stack * p =*top;
        int x =(*top)->data;
        *top =(*top)->next;
        free(p);
        return x;
    }
}
int peek(struct stack *top,int pos){
    struct stack *ptr =top,*prev;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr =ptr->next;
    }
    
    if (ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }

}
int main()
{
    struct stack * top =NULL;
    // LInkedlistTraversal(head);
    top =push(top,78);
    top =push(top,7);
    top =push(top,8);
    top =push(top,6);
    top =push(top,9);
    top =push(top,10);
    LInkedlistTraversal(top);
    // int Element =peek(top);
   
    for (int i = 1; i <= 6; i++)
    {
         printf("peek element %d:%d\n",i,peek(top,i));
    }
    
    // LInkedlistTraversal(top);


    return 0;
}