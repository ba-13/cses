// #include <iostream>
// #include <string>
// #include <utility>
#include "macro.hpp"
using std::pair;
using std::string;

//* Basic pair implementation
template <typename T1, typename T2>
struct myPair
{
    T1 first;
    T2 second;
};

//@l The great advantage of pairs is that they have built-in operations to compare themselves.
//@l They are compared to first-to-second element. If the first elements aren't equal, result will be based on that alone, and second element comparison gets short-cktd.
//@l Second elements are compared only when first ones are equal

int main()
{
    pair<string, pair<int, int>> P;
    string s = P.first;
    int x = P.second.first;
    int y = P.second.second;
    //@l vector of pairs are easy to be manipulated with STL built-in methods.

    //@l Example: if a array of integer points have to be arranged to form a polygon, put them as `vector< pair < double, pair < int, int > > >` where each element of vector is { polar angle, { x, y } }. One call to sorting function does the job.
}