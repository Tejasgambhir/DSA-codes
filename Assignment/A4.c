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
struct node * createNode( struct node * root,int data){
    struct node * head = root;
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if (head==NULL)
    {
        head = newNode;
        head->next =NULL;
        return head;
    }
    
    while (head->next!=NULL)
    {   
        head = head->next;
    }
    head->next =newNode;
    head = head->next;
    head->next =NULL;
    return root;
}
int main()
{
    struct node * head = NULL;
    head = createNode(head,3);
    LInkedlistTraversal(head);
    return 0;
}
    