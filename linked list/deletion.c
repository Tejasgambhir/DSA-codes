#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
void LInkedlistTraversal(struct node* ptr)
{
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n"); 
    
}
//First element deletion
struct node* deletion(struct node*head){
    struct node*ptr =head;
    head=head->next;
    free(ptr);
    return head;
}
// last element deletion
struct node* deletionAtLast(struct node*head){
    struct node*p =head;
    struct node*q =head->next;
    int i =0;
    while(q->next!=NULL){
        p=p->next;
        q =q->next;
        i++;
    }
    p->next=NULL;
    free(q);
    return head;
}
//deleting the element with the given value 
struct node* deletionAtGiven(struct node*head,int data){
    struct node*p =head;
    struct node*q =head->next;
    while(q->data != data && q->next != NULL){
        p=p->next;
        q =q->next;
    }
    if(q->data == data){
    p->next =q->next;
    free(q);
    }
    else{
        printf("Value is not in the list");
    }
    return head;
}
//deleting the element at the given index
struct node* deletionAtFirst(struct node*head,int index){
    struct node*p =head;
    struct node*q =head->next;
     int i=0;
     while (i!=index-1)
     {
        p=p->next;
        q=q->next;
        i++;
     }
     p->next =q->next;
     free(q);
     return head;
}

int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    // allocate memory  for nodes in the linked list in heap
    head=(struct node*)malloc(sizeof(struct node));
    second = head;
    // second=(struct node*)malloc(sizeof(struct node));
    // third=(struct node*)malloc(sizeof(struct node));

    // head->data=7;
    // head->next =second;
    // second->data=98;
    // second->next =third;
    // third->data=62;
    // third->next =NULL;
    for (int i = 0; i < 5; i++)
    {
        struct node * p = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        head->next =p;
        head = p;
    }
    head =NULL;
    LInkedlistTraversal(second);
    
    // head= deletionAtGiven(head,98);
    // LInkedlistTraversal(head);
    
    return 0;
}
    