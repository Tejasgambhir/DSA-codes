#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int Rno;
    Student(string Name,int Rollno){
        this->name=Name;
        this->Rno =Rollno;
    }
    void print(){
        cout<<this->name << " "<< this->Rno<<endl;
    }
};

int main()
{
    Student s1("Asif",25);
    Student s2("Sarth",23);
    s1 = s2;// copy assignment operator
    // s1.name = s2.name;
    // s1.Rno = s2.Rno;
    s1.print();
    s2.print();


return 0;
}