#include<stdio.h>
#include<stdlib.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int partitionIndex(int *A,int low,int high){
    int pivot = A[low];
    int i =low+1,temp;
    int j =high;
    do{
    while (pivot<=A[i])
    {
        i++;
    }
    while(pivot>A[j]){
        j--;
    }
    if(i<j){
        temp =A[i];
        A[i] =A[j];
        A[j] =temp;
    }
    }while(i<j);
    temp =A[low];
    A[j]= A[low];
    A[low] =temp;
    return j ;
}
void QuickSort(int *A,int high ,int low){
    int Index;
    if(low<high){
        Index =partitionIndex(A,low,high);
        QuickSort(A,low,Index-1);
        QuickSort(A,Index-1,high);
    }
}
int main()
{
    int A[] = {2,5,7,1,4};
    int n = 5;
    printArray(A, n);
    QuickSort(A,0,n-1);
    printArray(A, n);
    return 0;
}