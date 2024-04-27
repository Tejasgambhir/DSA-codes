#include <bits/stdc++.h>
using namespace std;
// polymorphism: existing multiple forms
/*
 Types of polymorphism:
                                              
 1)complie time polymorphism: 1) operator overloading  2) function overloading  

 2) run-time polymorphism: 1) method overiding
*/

// function overloading
class A{
    public:
    void func(){
        cout<<"inside func without argument"<<endl;
    }
    void func(string name){
        cout<<"inside func :"<<name<<endl;
    }
};

// operator overloading
class B{
    public:
    int a;
    void operator+(B &obj){
        int value = this->a;
        int val = obj.a;
        cout<<value-val<<endl;
    }
};
// method overiding 
class parent{
    public:
    void speak(){
        cout<<" parent class speaking"<<endl;
    }
};
class subclass : public parent{
    public:
    void speak(){
        cout<<"sub class speaking"<<endl;
    }
};

int main()
{
    // function overloading
 A a;
 a.func();
 a.func("Tejas");
 // operator overloading
 B c,d;
 c.a =5;
 d.a = 3;
  c+d;
  // method overiding
  subclass sb;
  sb.speak();
return 0;
}