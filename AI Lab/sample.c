#include<stdio.h>
#include<string.h>
int main()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(i+j == 76-(i*j)){
                printf("first Number is %d and second number is %d\n",i ,j);
            }
        }
        
    }
    
    return 0;
}