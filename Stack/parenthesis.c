#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
struct stack
{
    int size;
    int top;
    char *arr;
};
void printArray(char *a, int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%c ", a[i]);
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
void push(struct stack * p , char val){
    if(isFull(p)){
        printf("Stack overflow");
    }
    else{
        p->top++;
        p->arr[p->top] = val;
    }
}
void pop(struct stack * p ){
    if(isEmpty(p)){
        printf("Stack is empty!!");
    }
    else{
        p->top--;
    }
}
int  parenthesis(struct stack * sp ,char *ptr, int len){
    
//   printf("welcome");
//   printf("%d",len);
  printArray(ptr,strlen(ptr));
  for (int i = 0; ptr[i]!='\0'; i++)
  {
    if(ptr[i]=='('){
        push(sp,'(');
    }
    else if (ptr[i]==')'){
         if(isEmpty(sp)){
            return 0;
         }
         pop(sp);

    }
  }
//   printArray(sp->arr,len);
  return isEmpty(sp);
}
int main()
{
    char *exp ="(5*(9+0))";
    struct stack *sp;
    sp->size = strlen(exp);
    sp->top =-1;
    sp->arr =(char*)malloc(sp->size * sizeof(char));
    if(parenthesis(sp,exp,strlen(exp))){
        printf("parenthesis is matching\n");
    }
    else{
        printf("parenthesis is not macthing\n");
    }
    return 0;
}