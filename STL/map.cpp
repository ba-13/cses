// #include <iostream>
#include <map>
#include "macro.hpp"
using namespace std;

//* maps and sets are implemented as red-black trees.
//* both are sorted in ascending order while transversing these containers.
int main()
{
    map<string, int> M;
    M["top"] = 1;
    M["coder"] = 2;
    M["K"] = 13;
    int x = M["top"] + M["coder"];
    map<string, int>::const_iterator it;
    if ((it = M.find("SRM")) != M.end())
        cout << M["SRM"];

    //! Don't change key of map element with an iterator.
    //* a difference between .find and [---] is that prior will never change contents of map, while later will add a new element if it doesn't exist.
    // Thus don't use [---] if you don't want to add new elements
    it = M.find("K");
    it++;
    // this works, also with sets
}

void f(const map<string, int> &M)
{
    // if (M["thisCreatesNewElement"] == 42) // !this causes an error: Can't use [] on const map objects
    if (M.find("thisCreatesNoNewElement") == M.end())
        ;
}

vector<pair<string, int>> *createVectorFromMap(map<string, int> &M)
{
    // map<string, int> M;
    vector<pair<string, int>> V(all(M));
    return &V;
}