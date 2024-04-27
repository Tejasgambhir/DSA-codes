#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct queue{
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
int isFull(struct queue *q){
    if(q->b == q->size -1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if(q->b == q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue* q,int val){
    if (isFull(q))
    {
        printf("queue is full ");
    }
    else{
        q->b++;
        q->arr[q->b]=val;
    }
    
}
void dequeue(struct queue * q){
    if (isEmpty(q))
    {
        printf("this queue is empty");
    }
    else{
        q->f++;
    }
}
int main()
{
    struct queue q;
    q.size =5;
    q.f=q.b =-1;
    q.arr = (int *)malloc(q.size*sizeof(int));
    
    enqueue(&q,18);
    enqueue(&q,25);
    enqueue(&q,5);
    enqueue(&q,45);
    enqueue(&q,45);
    printArray(q.arr,q.b,q.f);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,90);
    printArray(q.arr,q.b,q.f);
    return 0;
}