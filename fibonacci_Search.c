#include<stdio.h>


int min ( int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
int fibonacci_search(int arr[],int target,int n){
    int a,b,c,offset;
    a=0;
    b=1;
    c=a+b;
    while (c<n)
    {
        a=b;
        b=c;
        c=a+b;
    }
    offset = -1;
    while(c>1){
       int i = min(offset+a,n-1);
       if(arr[i]<target){
        c=b;
        b=a;
        a=c-b;
        offset= i;
       }
       else if(arr[i]>target){
        c =a;
        b =b-a;
        a =c-b;
       }
       else{
        return i;
       }

    }
    if (b && arr[offset + 1] == target)
        return offset + 1;
    return -1;
    
}
int main()
{
    int a,b,c,n,arr[10],target;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the Element of an array(in sorted order): \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element to search: ");
    scanf("%d",&target);
    int index = fibonacci_search(arr,target,n);
    printf("Element %d is found at index %d\n",target,index);

    
    return 0;
}