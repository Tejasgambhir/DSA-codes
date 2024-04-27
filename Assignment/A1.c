#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
}
void insertionSort(int *A, int n)
{
    int ele, j;
    for (int i = 1; i < n; i++)
    {
        ele = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > ele) // 2,5,6,3,1
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = ele;
    }
}
void merge(int*A , int mid , int high , int low)
{
 int i,j,ele,b[100];
 i=low;
 j=mid+1;
 ele=low;
 while (i<=mid && j<=high)
 {
    if (A[i]<A[j]){
        b[ele]=A[i];
        i++;ele++;
    }
    else{
        b[ele]=A[j];
        j++;ele++;
    }
 }
 while(i<=mid){
    b[ele]=A[i];
    ele++;i++;
 }
 while(j<=high){
    b[ele]=A[j];
    ele++;j++;
 }
for (int i = low; i <= high; i++)
{
    A[i]=b[i];
}

 
}
void MergeSort(int *A, int low ,int high)
{
    int mid;
    if (low<high){
        mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        merge(A,mid,high,low);
    }
}
void Binarysearch(int*A,int n){
    int high = n-1;
    int low =0;
    int i =0,ele;
    printf("Enter the value  you want to find\n");
    scanf("%d",&ele);
    while (1)
    {
        int mid =(high + low)/2;
        if (A[mid]>ele)
        {
            high = mid-1;
        }
        else if(A[mid]==ele){
            printf("Element is found at %d index",mid);
            break;
        }
        else{
            low=mid+1;
        }
        
    }
    printf("\n");
}
    int main()
 {
        int a;
        do 
        {
            printf("Enter 1 for Insertion Sort\n");
            printf("Enter 2 for Merge Sort\n");
            printf("Enter 3 for Binary Search\n");
            printf("Enter 4 to exit\n");
            printf("Enter your choice\n");
            scanf("%d", &a);
            if (a == 1)
            {
                int n;
                printf("Enter the size of array\n");
                scanf("%d", &n);
                int A[n];
                for (int i = 0; i < n; i++)
                {
                    scanf("%d", &A[i]);
                }
                printf("These is your sorted array\n");
                insertionSort(A, n);
                printArray(A, n);
            }

            if (a == 2)
            {
                int n;
                printf("Enter the size of array\n");
                scanf("%d", &n);
                int A[n];
                for (int i = 0; i < n; i++)
                {
                    scanf("%d", &A[i]);
                }
                printf("These is your sorted array\n");
                printArray(A,n);
                MergeSort(A,0,n-1);
                printArray(A, n);
            }
            if (a == 3)
            {
                int n;
                printf("Enter the size of array\n");
                scanf("%d", &n);
                int A[n];
                for (int i = 0; i < n; i++)
                {
                    scanf("%d", &A[i]);
                }
                Binarysearch(A,n);

            }
            } while(a!=4);
        
    
        return 0;
 }