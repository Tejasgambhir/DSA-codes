#include <bits/stdc++.h>
using namespace std;
// getter and setter it's just a function that used to access the value of private variables
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
 Student rahul;
  rahul.setName("Rahul");
  cout<<rahul.getName()<<endl;
return 0;
}