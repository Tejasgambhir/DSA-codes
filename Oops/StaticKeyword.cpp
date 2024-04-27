#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    static int Rno;// static keyword for accessing Rno value you don't need to create object
    static int Random(){
        return Rno;
    }
};

int Student::Rno = 10;// :: <- Scope resolution operator 
int main()
{
    cout<<Student::Rno<<endl;
    Student s1;
    s1.Rno = 20;
    cout<<Student::Random()<<endl;
return 0;
}