#include <bits/stdc++.h>
using namespace std;
// private data member in super class we cannot access in child class
class human{ // parent class / super class
    public:
    int height=20;
    int weight= 10;
    int age= 70;
    void speak(){
        cout<<"speaking"<<endl;
    }
    int getAge(){
        return this->height;
    }
    void setAge( int Age){
        this->age = Age;
    }
};
// child class : mode parent class syntax
class male:protected human{
    // protected: Can be accessed by the class itself and by derived (child) classes.
    // private: Can only be accessed by the class itself; not accessible by derived (child) classes.
    public:
    string Color;
    void attack(){
        cout<<"male attacking"<<endl;
    }
    int getHeight(){
        return this->height;
    }
};

/*
 Types of inheritance:
    Single: One base class, one derived class.
    Multi-level: A chain of classes where each class serves as the base for the next class.
    Multiple: Multiple base classes, one derived class.
    Hybrid: Combination of multiple inheritance and multi-level inheritance.
    Hierarchical: One base class, m .
*/

class animal{
   public:
   void bark(){
    cout<<"barking"<<endl;
   }
};
// multiple inheritance
// hybrid : human + animal
class Hybrid : public animal,public human{
    
};


int main()
{
//   male m1;
// //   m1.height = 10;
// //   cout<<m1.age<<endl;
//   cout<<m1.getHeight()<<endl;
//   cout<<m1.weight<<endl;
//   m1.attack();


Hybrid h;
h.bark();
h.speak();

return 0;
}