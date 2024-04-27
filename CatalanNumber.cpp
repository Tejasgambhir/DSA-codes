#include <bits/stdc++.h>
using namespace std;

int solve(int n , int m){
    if(n<0 || m<0){
        return 0;
    }
    if(n == 0 && m==0){
        return 1;
    }
    if((n+m)%2==0 &&  n > m){
        return 0;
    }
    return solve(n-1,m)+solve(n,m-1);
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
    cout<< "Catalan Number : "<<solve(i,i)<<endl;
    }
    
    return 0;
}