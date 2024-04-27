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
void Merge(int *A,int *B,int n ) {
    int i,j,k;
    i=j=k=0;
    int c[100];
    while (i<n && j<n)
    {
        if (A[i]>B[j]){ 
            c[k]=B[j];
            j++;k++;
        }
        else{
            c[k]=A[i];
            i++;k++;
        }
        
    }
    while (i<n)
    {
       c[k]=A[i];
       i++,k++;
    }
    while (j<n)
    {
        c[k]=B[j];
       j++,k++;
    }
    printArray(c,2*n);
}
int main()
{
    int A[] = {1,2,3,6,7};
    int B[] ={5,6,7,8,9};
    int n = 5;
    // printArray(A, n);
    Merge(A,B,n);
    // printArray(A, n);
    return 0;
}