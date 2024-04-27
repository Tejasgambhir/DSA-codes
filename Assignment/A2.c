#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char*arr;
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
int match (char a, char b){
    if(a=='(' && b ==')'){
        return 1;
    }
    if(a=='{' && b =='}'){
        return 1;
    }
    if(a=='[' && b ==']'){
        return 1;
    }
    return 0;

}

int  parenthesis(struct stack * sp ,char *ptr){
//   printArray(ptr,strlen(ptr));
  
  for (int i = 0; ptr[i]!='\0'; i++)
  {
    if(ptr[i]=='(' || ptr[i]=='{' || ptr[i]=='['){
        push(sp,ptr[i]);
    }
    else if (ptr[i]==')' || ptr[i]==']'|| ptr[i]=='}'){
         if(isEmpty(sp)){
            return 0;
         }
         else if(match(sp->arr[sp->top],ptr[i])){
            pop(sp);
         }
         else{
            return 0;
         }
    }

  }
  return isEmpty(sp);
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

char solvingPostfix(struct stack * sp,char*postfix){
    int i =0;
    char a, b;
    while(postfix[i]!='\0'){
       if (postfix[i]=='*' || postfix[i] == '+' || postfix[i] == '-' || postfix[i] =='/')
       {
        int val;
        a=pop(sp);
        b= pop(sp);

        switch (postfix[i])
        {
        case '+':
            val = ((int)(b)-48)+((int)(a)-48);
            break;
        case '-':
            val = ((int)(b)-48)-((int)(a)-48);
            break;
        case '*':
            val = ((int)(b)-48)*((int)(a)-48);
            break;
        case '/':
            val = ((int)(b)-48)/((int)(a)-48);
            break;
        
        default:
            break;
        }
        push(sp, val + '0');
       }
       else
       {
        push(sp,postfix[i]);
       }
       i++;
    }
    return sp->arr[sp->top];
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
    
    int a;
    do
    {
        printf("1. Balanced Parenthesis\n");
        printf("2. Infix to postfix\n");
        printf("3. Solving postfix expression\n");
        printf("4.  Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&a);
        if (a==1)
        {
            char str[50];
            printf("Enter Expression: \n");
            scanf("%s",&str);
            struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
            sp->size = 100;
            sp->top =-1;
            sp->arr =(char*)malloc(sp->size*sizeof(char));
            if(parenthesis(sp,str)){
                printf("parenthesis is matching\n");
            }
            else{
                printf("parenthesis is not macthing\n");
            }
            
        }
        if (a==2)
        {
            char str[50];
            printf("Enter Expression: \n");
            scanf("%s",&str);
            printArray(infixTOpostfix(str),strlen(str));
        }
        if (a==3)
        {
            char str[50];
            printf("Enter Expression: \n");
            scanf("%s",&str);
            struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
            sp->size = 100;
            sp->top =-1;
            sp->arr =(char*)malloc(sp->size*sizeof(char));
            printf("The answer of your expression  is %d\n",(int)solvingPostfix(sp,str) - '0');
        }
    } while (a!=4);
    
    return 0;
}