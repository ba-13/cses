// #include <iostream>
// #include <string>
// #include <vector>
#include "macro.hpp"
#include <sstream>
using std::string;

int intro()
{
    // do remember that when something needs range, we specify start iterator which is included and the end iterator which itself isn't included in the range
    string s = "hello";
    string s1 = s.substr(0, 3);              // hel
    string s2 = s.substr(0, s.length() - 1); // hell
    string s3 = s.substr(2);                 // llo
    //! WARNING: `s.length() - 1` in an empty string gives errors cause s.length() is unsigned, and unsigned(0) - 1...
}

int main()
{
    // istringstream allows for reading a string like from an input stream
    // ostringstream used to formatting output
}

void fi(const std::string &s)
{
    std::istringstream is(s);
    std::vector<int> v;
    int tmp;
    while (is >> tmp)
    {
        v.push_back(tmp);
    }
}

string fo(const std::vector<int> &v)
{
    std::ostringstream os;

    // copy all elements from vector to a string stream as text
    for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
        os << " " << *it;

    std::string s = os.str();

    // removing the first space character
    if (!s.empty())
        s = s.substr(1);
    return s;
}