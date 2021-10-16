// #include <iostream>
// #include <set>
// #include <random>
#include "macro.hpp"
#include <ctime>
using std::set;

int main()
{
    /**
     * set is described as the one with features:
     * add element, but don't allow duplicates # O(log n)
     * remove elements # O(log n)
     * get count of elements # O(1)
     * check if an element is present # O(log n)
     */
    set<int> s;
    std::time_t t = std::time(0);
    std::mt19937 mt(69);
    // std::mt19937 mt(t);
    std::uniform_int_distribution<int> dist(1, 1000);
    for (int i = 0; i < 100; i++)
    {
        int tmp = dist(mt);
        s.insert(tmp);
        std::cout << tmp << " ";
    }
    std::cout << "\n"
              << (int)s.size();

    for (int i = 2; i <= 1000; i += 2)
        s.erase(i);

    set<int>::iterator it;        // use this if you have intention of changing the values
    set<int>::const_iterator cit; // use this if you have no intention of changing the values
    std::cout << "\n";

    for (cit = s.begin(); cit != s.end(); cit++)
        std::cout << *cit << " ";

// assume we have the following set
#include <vector>
#include <utility>
#include <string>
    using std::pair;
    using std::string;
    using std::vector;
    set<pair<string, pair<int, vector<int>>>> SS;
    // to transverse this, with iterator declaration, would be hard. Thus use the macro we defined
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
    int total = 0;
    tr(SS, it)
    {
        total += it->second.first;
        // total += (*it).second.first; // this is valid too
    }

    /**
     * * .find() in sets
     * if found, returns an iterator at that location
     * else returns .end()
     *
     * * Its alternative is .count(), which works in multiset as well ofc
     * but .count() in sets makes a bit less sense
     * so use .find() for sets
     */
    if (s.count(42))
        std::cout << "Found 42 with count";
    if (s.find(42) != s.end())
        std::cout << "Found 42 with find";

        //* else define a macro:
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(container.begin(), container.end(), element) != container.end())

    s.erase(29); // erasing a single element if present

    set<int>::iterator it1, it2;
    it1 = s.find(10);
    it2 = s.find(100);
    s.erase(it1, it2); //@l erasing a range, here, 10 included but 100 isn't. and sets store elements in ascending order
    // so everything [10, 100) will be erased

    //* Interval constructor of sets
    int data[5] = {1, 3, 2, 6, 4};
    set<int> s1(data, data + 5);

    //! This provides a simple way to sort and remove duplicates in a vector
    vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = dist(mt);
    set<int> s(v.begin(), v.end());
    vector<int> vSorted(s.begin(), s.end());

    //! Any comparable element can be stored in a set
}