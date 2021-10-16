// #include <iostream>
// #include <utility>
// #include <vector>
// #include <algorithm>
// #include <set>
#include "macro.hpp"
#include <iterator>

using std::swap;
using std::vector;
const int debugging = true;
#define deb(x)     \
    if (debugging) \
        std::cout << #x << " " << x << "\n";

//* STL iterators are a general way to access data in containers
//@l To transverse or manipulate a container, a pointer is a more convinient way, and iterators are just abstract pointers

void reverse_array(int *A, int N)
{
    int *first = A, *last = A + N - 1;
    while (first < last)
    {
        swap(*first, *last);
        first++;
        last--;
    }
}
// if this can be abstracted to any container...
/**
 * ! These are defined for an iterator
 * get value of iterator, `*it`
 * increment-decrement iterators
 * compare iterators via "!=" or "<" or similar
 * add immediate to iterator, `+= 13` shift 13 element forward
 * get distance between iterators `it2 - it1`
 * range checking of container
 * profiling container usage
 */

//@l It is impossible to implement the above operations in O(1) for all containers
//@l Normal Iterators: can be compared by `==` or `!=` and incremented or decremented
//@l Random access iterators: can do all above

// Generalised reverse_algo for any object type that supports normal iterators
template <typename T>
void reverse(T *first, T *last)
{
    if (first != last)
    {
        while (true)
        {
            swap(*first, *last);
            first++;
            if (first == last)
                break;
            last--;
            if (first == last)
                break;
        }
    }
}

/**
 * @l STL algo always uses 2 iterators, `begin` and `end`.
 * `end` points at the first invalid object, the object directly following the last valid one in memory.
 * each STL container has functions `begin()` and `end()` that return those iterators
 * c.begin() == c.end() only when c is empty
 * c.begin() - c.end() is c.size(), but this works only when iterators are random accessible. So, not valid for doublylinkedlist.
 * @l Each container also have rbegin() and rend() iterators, which are used to iterate in reverse order, which must be a bidirectional iterator.
 * rend() points to the element left of the first element of the array/container (begin() points to the first element)
 * rbegin() points to the last element of the container (end() points to the object right of that)
 * ! Use `!=` or `==` or `++` or `--` assuming normal iterators, else they tend to misbehave.
 * * Some useful macros can be `#define all(c) c.begin(), c.end()`
 * ! `.size()` in STL is unsigned
 */

// Equivalent function to std::reverse(T begin, T end);
template <typename T>
void reverse_stl_compliant(T *begin, T *end)
{
    // as end doesn't point to last object, we need to decrement that, but taking care if container is empty
    if (begin != end)
        end--;
    else
        return;
    if (begin != end) // i.e. only one object
    {
        while (true)
        {
            swap(*begin, *end);
            begin++;
            if (begin == end)
                break;
            end--;
            if (begin == end)
                break;
        }
    }
}

int iteratorBasics()
{
    vector<int> v;
    v.push_back(13);
    v.push_back(36);
    v.push_back(69);
    v.push_back(89);
    v.push_back(269);
    // v.push_back(347);

    vector<int> v2(v);
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << " ";
    std::cout << "\n";

    vector<int> v3(v.begin(), v.end() - 1);
    for (int i = 0; i < v3.size(); i++)
        std::cout << v3[i] << " ";
    std::cout << "\n";

    vector<int> v4(v.begin(), v.begin() + v.size() / 2);
    for (int i = 0; i < v4.size(); i++)
        std::cout << v4[i] << " ";
    std::cout << "\n";

    vector<int> v5(v.rbegin() + v.size() / 2 + 1, v.rend());
    for (int i = 0; i < v5.size(); i++)
        std::cout << v5[i] << " ";
    std::cout << "\n";

    int data[10] = {1, 2, 3, 1, 14, 5, 71, 1}; // rest 2 are 0s by default
    vector<int> vec(data, data + 10);
    int max = *std::max_element(vec.begin(), vec.end()); // returns the ptr which is dereferenced
    int maxIndex = std::max_element(vec.begin(), vec.end()) - vec.begin();
    int min = *std::min_element(vec.begin(), vec.end() - 2);
    int minIndex = std::min_element(vec.begin(), vec.end() - 2) - vec.begin();
    deb(max);
    deb(maxIndex);
    deb(min);
    deb(minIndex);

    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    std::sort(vec.rbegin(), vec.rend());
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    //* Initiating an iterator is easy
    vector<int>::iterator itr = v.begin();

    const vector<int> vConst(v);
    vector<int>::const_iterator itrC = vConst.begin();

    //* typeof: replaces the type of expression during compilation
    // defined in g++ or gcc
    typeof(max + min) x = (max + min);
    // is converted to int x = (max + min) during pre-processing
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)

    //! iterators are necessary for containers that don't have indexing, but we need to access data.
}

//@param  container, pointer_to_starting_location
int inserters()
{
    //! inserter: creates an insert_iterator that can be used to insert new elements into container in successive locations starting at position pointed by it.
    std::multiset<int> s{1, 2, 3};

    // std::inserter is commonly used with multi-sets
    std::fill_n(std::inserter(s, s.end()), 5, 2);

    for (int n : s)
        std::cout << n << ' ';
    std::cout << '\n';

    std::vector<int> d{100, 200, 300};
    std::vector<int> v{1, 2, 3, 4, 5};

    // when inserting in a sequence container, insertion point advances
    // because each std::insert_iterator::operator= updates the target iterator
    std::copy(d.begin(), d.end(), std::inserter(v, std::next(v.begin())));
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';

    //? see the difference
    // copy overwrites, inserter makes sure it doesn't happen
    v.erase(v.begin(), v.end());
    std::cout << v.size() << "\n";
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::copy(d.begin(), d.end(), v.begin() + 1);
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';
}

int main()
{
    inserters();
    return 0;
}