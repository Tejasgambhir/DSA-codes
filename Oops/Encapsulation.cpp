#include <bits/stdc++.h>
using namespace std;
// Encapsulation : wrapping  up data member / functions
// Encapsulation : information hiding
// full Encapsulate class : all data members are private 

class Student{
    string name;
    int Rno;
    public:
    string getName(){
        return name;
    }
    void setName(string Name){
      this->name = Name;// this keyword store the address  of current object  
                        // this keyword is the pointer 
    }
};

int main()
{
Student s1;
cout<<"Everything Fine"<<endl;
return 0;
}