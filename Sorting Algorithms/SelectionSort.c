#include<stdio.h>
#include<string.h>
void printArray(int*a , int n){
   for (int i = 0; i < n; i++)
   {
     printf("%d ",a[i]);
   }
   printf("\n");
}
void sort(int * A , int n){
    int temp;
    for (int i  = 0; i < n; i++)
    {
        int min =10;
        for (int j= i; j< n; j++)
        {
            if (A[j]<min)
            {
                min=A[j];
                temp=A[i];
                A[i]=min;
                A[j]=temp;
            }
            
        }
        
    }
    
}
int main()
{
    int A[]={2,4,0,1,3};
    int n=5;
    printArray(A,n);
    sort(A,n);
    printArray(A,n);

    return 0;
}