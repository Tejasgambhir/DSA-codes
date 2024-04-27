#include <bits/stdc++.h>
using namespace std;
// constructor is the function that invoke when we created object and also we can pass the argument in the constructor
class Student{
    public:
    string name;
    int Rno;
    Student(string N){
        this->name = N;
        // cout<<"i am in "<<endl;
    }
    // Student(Student& temp){// this is copy constructor you need to pass by reference
    //     cout<<"Inside copy constructor"<<endl;
    //     this->name = temp.name;
    //     // cout<<"i am in "<<endl;
    // }
    void print(){
        cout<<this->name<<endl;
    }
};
// default constructor contains
// object creation invoke
// No return type
//No i/p parameter
int main()
{
 Student s1("tejas");
 s1.print();
 //copy constructor
 Student s2(s1);
 s2.name[0]= 'c';// default constructor use shallow copy (Access same memory)
// deep copy : create a new copy 
 s2.print();
 s1.print();

return 0;
}