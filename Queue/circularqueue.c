#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct circularqueue{
    int size;
    int f;
    int b;
    int *arr;
};
void printArray(int *a, int n,int start)
{
    for (int i = start+1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int isFull(struct circularqueue *q){
    if((q->b + 1)%q->size == q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct circularqueue *q){
    if(q->b == q->f){
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
        q->b=(q->b+1)%q->size;
        q->arr[q->b]=val;
    }
    
}
void dequeue(struct circularqueue * q){
    if (isEmpty(q))
    {
        printf("this circularqueue is empty");
    }
    else{
        q->f=(q->f+1)%q->size;
    }
}
int main()
{
    struct circularqueue q;
    q.size =5;
    q.f=q.b =0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    
    enqueue(&q,18);
    enqueue(&q,25);
    enqueue(&q,5);
    enqueue(&q,45);
    printArray(q.arr,q.b,q.f);
    dequeue(&q);
    dequeue(&q);
    
    printArray(q.arr,q.b,q.f);
    return 0;
}