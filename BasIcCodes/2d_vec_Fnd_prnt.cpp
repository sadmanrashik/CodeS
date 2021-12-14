#include "stdc+.h"
// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{   //basic 2d vector;
    vss g1(50001);
    
    
    g1[0].push_back("dawd");
    g1[0].push_back("wd");
    g1[0].push_back("dasdwd");
    g1[0].push_back("fwawad");
    
    cout << "Output of begin and end: ";
    for (auto i = g1[0].end()-1; i >= g1[0].begin(); --i)  //definite row reverse print
        cout << *i << " ";
    
    cout<<g1[1].empty(); //check if a row is empty
    

    return 0;
}
