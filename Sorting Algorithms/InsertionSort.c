#include <stdio.h>
#include <string.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void InsertionSort(int*A,int n){
    int key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
        printArray(A,n);
        

    }
    
}
int main()
{
    int A[] = {2, 4, 0, 1, 3};
    int n = 5;
    // printArray(A, n);
    InsertionSort(A, n);
    // printArray(A, n);
    return 0;
}