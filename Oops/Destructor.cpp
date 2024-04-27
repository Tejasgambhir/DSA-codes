#include <bits/stdc++.h>
using namespace std;

// destructor is use to deallocate the memory 
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
    ~Student(){
        cout<<"inside destructor"<<endl;
    }
};
int main()
{
//static allocation destructor automatically called
Student s1("A",20);
// Dynamic allocation  destructor manually called
Student * s2 = new Student("A",30);
delete s2;

return 0;
}