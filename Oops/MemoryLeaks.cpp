#include <bits/stdc++.h>
using namespace std;
int main()
{
    int *myp;
    // good way to write code
    try
    {
        myp = new int[10000];
    }
    catch(...)
    {
        cout<<"failed in allocating memory"<<endl;
    }
    delete[] myp;//entire memory deleted
    
return 0;
}