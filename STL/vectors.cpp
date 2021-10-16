// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <random>
#include "macro.hpp"
using std::cin;
using std::cout;
using std::vector;
// using namespace std;

int func(vector<int>);         //! Never do this
int bar(vector<int> &v);       //* This is OK, you're passing the address
int foo(const vector<int> &v); //* This is OK, no intention to change values

namespace std
{
    // vector< vector < int > > ThisIsCorrect;
    // vector<vector<int>> CompilerCanBeConfusedByRightShiftOperator;
    int initialVectorKnowledge()
    {
        vector<int> v;
        //* Vector is back-compatible with C, cause it's THE ARRAY, with some features.
        vector<int> try1(10);
        int n;
        vector<int> try2(n);
        vector<int> try3(v.begin(), v.end()); // iterator/ptr constructor argument, initiates the vector with that range of values
        int size = v.size();
        //@l Vectors can report it's size `.size()` which takes time.
        bool is_empty = v.empty();
        //@l Use `v.empty()` to check for a null vector
        v.push_back(0);
        //@l `.push_back()` adds an element to the end of vector. A vector doesn't allocate a single element, but more than it actually needs.
        v.resize(10);
        //@l to resize ofc, add/remove more elements once at a time. It resizes truly, so push_back will add new space, and not into it.
        v.clear();
        //@l Clears, destroys the container
        vector<int> v2(100, 13);
        //@l to initiate with a finite size (of 100), and with a default value (of 13)
        vector<vector<int>> Matrix;
        int M, N;
        vector<vector<int>> Mat(M, vector<int>(M, -1));
        //@l The above will create a M*N matrix with -1 filled throughout
        func(v);
        foo(v);
        bar(v);
        //@l Check out the function declaration
        //@l When vector is passed as a parameter, a copy is created. It takes a lot of time and memory, and is never usually needed.
        //@l parameter acceptance with `const` implies you aren't going to change the value
    }

    int dataManipulationInVector() // Common in all STL containers, but not identical
    {
        //* Insertion
        vector<int> v;
        v.insert(v.begin() + 1, 42);
        // inserts 42 at index 1, and causes shifting of later indices
        int insertThis[10];
        vector<int> insertThisToo(10);
        v.insert(v.begin() + 2, insertThis, insertThis + 10);
        // this is to insert array of data, the end ptr is not included in insertion
        v.insert(v.begin() + 3, insertThisToo.begin(), insertThisToo.end());

        //* Deletion
        v.erase(v.begin() + 4);
        // erase single or range of elements
        v.erase(v.begin() + v.size() / 2, v.end() - v.size() / 4);
    }

    int memoryManagement()
    {
        // most STL implementations allocate double the size when push_back is invoked
        vi v;
        v.reserve(10);
        fr(i, 8)
            v.pb(24);
        // reserve allots the specified number of memory spaces to the vector, pb and reserve are good
        // another pattern is to use:
        v.reserve(50);
        copy(v.begin(), v.end(), back_inserter(v));

        // now if you decide that no more allocation is needed, so remove extra allocation
        vi(all(v)).swap(v);
        // this means: create a tmp vector with the same contents as v, then swap that vector with v, original vector is disposed
    }
}