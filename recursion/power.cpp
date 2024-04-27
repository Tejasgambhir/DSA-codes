#include <bits/stdc++.h>
using namespace std;


int power(int a , int b){
    
    if(b==0){
        return 1;
    }
    int ans = power(a,b/2);
    if(b%2==0){
          return ans * ans ;
    }
    else{
        return a * ans * ans ;
    }
}

int main(int argc, char const *argv[])
{
    int a,b;
    cin>>a>>b ;
    cout<< "Answer is  " << power(a, b)<<endl;
    return 0;
}