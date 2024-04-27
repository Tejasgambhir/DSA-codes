#include <bits/stdc++.h>
using namespace std;
class A{
    public:
    void func1(){
        cout<<"A"<<endl;
    }
};
class B{
    public:
    void func1(){
        cout<<"B"<<endl;
    }
};
class C:public A ,public B{
    public:
    void func3(){
        cout<<"Funct3"<<endl;
    }
};
int main()
{
    C c;
    c.A::func1();// we solve ambiguity using scope resolution operator
    c.B::func1();
return 0;
}