#include<stdio.h>
#include<string.h>
void printArray(int*a , int n){
   for (int i = 0; i < n; i++)
   {
     printf("%d ",a[i]);
   }
   printf("\n");
}
int partition(int*A,int low,int high){
    int pivot=A[low];
    int i =low+1;
    int j = high;
    int temp;
    do
    {
    while (A[i]<=pivot)
    {
        i++;
    }
    while (A[j]>pivot)
    {
        j--;
    }
    if(i<j){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    } while (i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    printArray(A,5);
    return j;
}
void Quicksort(int*A,int low,int high){
    int partitionIndex;
    if (low<high){
    partitionIndex=partition(A,low,high);
    Quicksort(A,low,partitionIndex-1);
    Quicksort(A,partitionIndex+1,high);
    }
}
int main()
{
    int A[] = {2,5,7,1,4};
    int n=5;
    printArray(A,n);
    Quicksort(A,0,n-1);
    printArray(A,n);
    return 0;
}