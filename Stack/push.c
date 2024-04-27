#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
void printArray(int *a, int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int isFull(struct stack * p){
    if (p->top == p->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack * p){
    if (p->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack * p , int val){
    if(isFull(p)){
        printf("Stack overflow");
    }
    else{
        p->top++;
        p->arr[p->top] = val;
    }
}
void pop(struct stack * p ){
    if (isEmpty(p)){
        printf("Stack is empty!!");
    }
    else{
        p->top--;
    }
}
int main()
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size =20;
    sp->top =-1;
    sp->arr = (int*)malloc(sp->size * sizeof(int));

    push(sp,10);
    push(sp,11);
    push(sp,12);
    printArray(sp->arr,sp->top);
    pop(sp);
    printArray(sp->arr,sp->top);



    return 0;
}