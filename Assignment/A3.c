#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct circularqueue
{
    int size;
    int f;
    int r;
    int*arr;
};
struct queue{
    int size;
    int f;
    int r;
    int * arr;
};
void printArray(int *a, int end,int start)
{
    for (int i = start; i < end; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int isFull(struct circularqueue *q){
    if((q->r + 1)%q->size == q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct circularqueue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct circularqueue* q,int val){
    if (isFull(q))
    {
        printf("circularqueue is full ");
    }
    else{
        q->arr[q->r]=val;
        q->r=(q->r+1)%q->size;
    } 
}

void dequeue(struct circularqueue * q)
{
    if (isEmpty(q))
    {
        printf("this circularqueue is empty");
    }
    else{
        q->f=(q->f+1)%q->size;
    }
}
void enqueues(struct queue* q,int val){

        q->arr[q->r]=val;
        q->r++;
    
}
int main()
{
    int a,b; 
    struct circularqueue q;
    q.f= q.r=0;
    do
    {
        
        printf("1.Circular Queue\n");
        printf("2.Reverse stack using Queue\n");
        printf("3.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&a);
        if (a==1)
        {
            int Ele;
            printf("Enter the number of element\n");
            scanf("%d",&q.size);
            q.arr =(int*)malloc(q.size*sizeof(int));
            // printf("Enter the circular queue\n");
            // for (int i = 0; i < q.size; i++)
            // {
            //     scanf("%d",&q.arr[i]);
            // }
            // printf("\n");
            
            do
            {
                printf("1.Enqueue\n");
                printf("2.Dequeue\n");
                printf("3.Exit\n");
                printf("Enter the choice\n");
                scanf("%d",&b);
                if (b==1)
                {
                    int c;
                    printf("Enter the number\n");
                    scanf("%d",&c);
                    enqueue(&q,c) ;
                    printArray(q.arr,q.r,q.f);
                }
                if (b==2)
                {
                    dequeue(&q);
                    printArray(q.arr,q.r,q.f);
                }
                
            } while (b!=3);
            
        }
        if(a==2){
            int sz,a,i=0;
            struct queue q;
            q.f=q.r=0;
            printf("Enter the size of queue\n");
            scanf("%d",&sz);
            q.arr = (int*)malloc(sz*sizeof(int));
            printf("Enter the number\n");
            while (sz!=i)
            {
                scanf("%d",&a);
                enqueues(&q,a);
                i++;
            }

            // printf("%d",q.r);
            printArray(q.arr,q.r,q.f);
        }

    } while (a!=3);
    
    return 0;
}
