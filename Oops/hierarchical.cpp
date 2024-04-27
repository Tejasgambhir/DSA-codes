#include <bits/stdc++.h>
using namespace std;
// hierarchical
class A{
    public:
    void func1(){
        cout<<"Funct1"<<endl;
    }
};
class B: public A{
    public:
    void func2(){
        cout<<"Funct2"<<endl;
    }
};
class C:public A{
    public:
    void func3(){
        cout<<"Funct3"<<endl;
    }
};
int main()
{
     A a;
     a.func1();
     B b;
     b.func1();
     b.func2();
     C c;
     c.func1();
     c.func3();
return 0;
}