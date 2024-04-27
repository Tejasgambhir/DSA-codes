#include <bits/stdc++.h>
using namespace std;
// abstraction : implementation hiding



// Encapsulation means-hiding data like using getter and setter etc.
// Abstraction means- hiding implementation using abstract class and interfaces etc
class Student{
    string name;
    int Rno;
    public:
    string getName(){
        return name;
    }
    // Implementation of function setName is hidden : abstraction
    void setName(string Name){
      this->name = "{" + Name + "}";                                
    }
};
int main()
{

return 0;
}