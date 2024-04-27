#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int precedence(char ch){
    if(ch=='*' || ch =='/'){
        return 3;
    }
    else if(ch=='+' || ch =='-'){
        return 2;
    }
    else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch=='*' || ch =='/'||ch=='+' || ch =='-'){
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
char pop(struct stack * p ){
    char val;
    if(isEmpty(p)){
        printf("Stack is empty!!");
    }
    else{
        val =p->arr[p->top];
        p->top--;
    }
    return val;
}
char * infixTOpostfix(char*infix){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = strlen(infix);
    sp->top =-1;
    sp->arr =(char*)malloc(sp->size * sizeof(char));
    char*postfix = (char*)malloc(sp->size * sizeof(char));
    int i,j;
    i=j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;j++;
        }
        else{
            if(precedence(infix[i])>precedence(sp->arr[sp->top])){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j] =pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] ='\0';
    return postfix;
}
int main()
{   
    char*infix ="a-b/c";
    printArray(infix,strlen(infix));
    printArray(infixTOpostfix(infix),strlen(infix));
    return 0;
}