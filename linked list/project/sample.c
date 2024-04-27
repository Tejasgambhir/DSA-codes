#include<stdio.h>
#include<string.h>
int main()
{
    FILE *ptr =NULL;
    char *str;
    ptr =fopen("Order.txt","a");
    gets(str);
    fprintf(ptr,"\n%s",str);
    
    return 0;
}