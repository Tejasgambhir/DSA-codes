#include <bits/stdc++.h>
using namespace std;


// the size of object 
// In the case of empty class : 1
class Student{
    string name;
    int Rno;
};


int main()
{
 // static allocation
 Student s1;
 // dynamically allocation
 Student * s = new Student;
 cout<<sizeof(s1)<<endl;// sizeof(s1) is 40 not 36 : It happens because padding and greedy alignment 
 // Padding refers to the extra bytes added by the compiler to align data members within a class or struct
 // Greedy alignment refers to a strategy used by some compilers to minimize the amount of padding added to a class or struc
return 0;
}