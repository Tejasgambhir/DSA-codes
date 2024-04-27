#include<stdio.h>
#include<string.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void insertion(int A[],int n,int Element){
    for (int i = n-1; i >=0; i--)
    {
        if(A[i]>Element){
            A[i+1]=A[i];
        }
        else{
            A[i+1]=Element;
            break;
        }
    }
    
}
int main()
{ int A[10] = {0,1,2,4,6};
    int n = 5,element;
    printf("Enter the element \n");
    scanf("%d",&element);
    printArray(A, n);
    insertion(A, n,element);
    printArray(A, n+1);
    return 0;
}