#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node * next;
};
void LInkedlistTraversal(struct node* ptr){
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n"); 
    
}
struct node * insertAtbeginning(struct node*head,int data){
    struct node*ptr= (struct node*)malloc(sizeof(struct node));
    ptr->next =head;
    ptr->data=data;
}
int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    // allocate memory  for nodes in the linked list in heap
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next =second;
    second->data=98;
    second->next =third;
    third->data=62;
    third->next =NULL;
    LInkedlistTraversal(head);
    head=insertAtbeginning(head,65);
    LInkedlistTraversal(head);

    return 0;
}