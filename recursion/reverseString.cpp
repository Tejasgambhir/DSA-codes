
#include <bits/stdc++.h>
using namespace std;

void reverse(int i , int n , string s){
    if(i==n){
       return ;
    }
    reverse(i+1,n,s);
    cout<<s[i]<<"";
}
int main(int argc, char const *argv[])
{
    string s = "Tejas";
    reverse(0,5,s);
    // cout<<s<<endl;
    return 0;
}
