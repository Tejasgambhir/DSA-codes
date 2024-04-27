#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
void LInkedlistTraversal(struct node* ptr){
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n"); 
    
}
void transverse(struct node* head){
    struct node*ptr =head;
    struct node*prev;
    int i=0;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        prev = ptr;
        ptr =ptr->next;
    }
    ptr = prev;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr =ptr->prev;
    }
    
}

int main()
{   struct node * head;
    struct node * second;
    struct node * third;
    // allocate memory  for nodes in the linked list in heap
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next =second;
    head->prev =NULL;

    second->data=98;
    second->next =third;
    second->prev = head;

    third->data=62;
    third->next =NULL;
    third->prev =second;

    // transverse(head);
    LInkedlistTraversal(head);
    return 0;
}