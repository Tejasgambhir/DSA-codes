#include<stdio.h>
#include<string.h>
#include<math.h>
int nextBitStream(int num){
    int count=0;
    while(num%10!=0){
        num=num/10;
        count++;
    }
    num= (num+1)*pow(10,count);
    return num;
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    while(num!=1111)
    {
    num = nextBitStream(num);
    printf("next bit stream : %d\n",num);
    }
    
    
    return 0;
}