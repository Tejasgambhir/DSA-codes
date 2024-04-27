#include <bits/stdc++.h>
using namespace std;


// Access modifier 1:public 2:private 3:protected
class hero{
    public:
    int level;
    string name;
}; // by default it is private variable or data member

int main()
{
 hero suresh;
//  cout<<suresh.level<<" "<<suresh.name<<endl; that shows error because we are trying to access private variable
 cout<<suresh.level<< ""<<suresh.name<<endl;
return 0;
}