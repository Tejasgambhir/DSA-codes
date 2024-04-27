#include <bits/stdc++.h>
using namespace std;

void add(string a,string b,int carry,int i){
    // cout<<"inside"<<endl;
    
    if(i ==0){
    int A = a[i] -'0';
    int B = b[i] - '0';
    int C = A + B + carry;
    cout<<C;
    return ;
    }
    int A = a[i] -'0';
    int B = b[i] - '0';
    int C = A + B + carry;
    
    int value = C%10 ;
    i--;
    add(a,b,C/10,i);
    cout<<value; 
}

int main(){
    string a,b;
    cout<<"Enter the first number"<<endl;
   
    cin>>a;
    cin.ignore(); 
    cout<<"Enter the second number"<<endl;
    cin>>b;
    // cout<<a<<" "<<b<<endl;
    cout<<"Result: ";
    add(a,b,0,a.size()-1);
}