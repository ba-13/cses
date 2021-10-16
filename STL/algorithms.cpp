// #include <algorithm>
// #include <utility>
// #include <random>
// #include <vector>
// #include <iostream>
#include "macro.hpp"

template <class Container>
std::insert_iterator<Container> inserter(Container &c, typename Container::iterator i)
{
    return std::insert_iterator<Container>(c, i);
}

int main(int argc, char **argv)
{
    int a, b;
    std::mt19937 mt(13);
    std::uniform_int_distribution<int> dist(1, 100);
    a = dist(mt);
    b = dist(mt);
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(dist(mt));
    std::cout << "Initial Vector values: ";
    for (int i = 0; i < v.size(); i++)
        std::cout
            << v[i] << " ";
    std::cout << "\n";
    //! basic 3 algo
    std::max(a, b);
    std::min(a, b);
    std::swap(a, b);

    //! sorting : works for random access containers
    sort(v.begin(), v.begin() + v.size() / 2); // in-place, sorting the first half of vector
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    sort(v.rbegin(), v.rend() - v.size() / 2); // in-place, sorting the second half of vector in descending order
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    //! .find() : returns the iterator pointing to the location of the element, else container.end()
    // you can specify the range where to find, `.find(begin, end, element)
    // takes O(N) for all, O(log n) for sets and maps
    auto itr = find(v.begin(), v.end(), 29);
    auto itr2 = find(v.begin(), v.end(), 76);
    auto itr3 = find(v.begin(), v.begin() + v.size() / 2, 76);
    std::cout << "\n"
              << itr - v.begin(); // 10, not found
    std::cout << "\n"
              << itr2 - v.begin(); // 6
    std::cout << "\n"
              << itr3 - v.begin(); // 5, not the real v.end(), but the end passed to the function
    //! .count() : returns the number of occurrences in a part of container
    // takes O(N) for all, O(log n) for sets and maps

    //! next_premutation() : next_permutation(begin, end) makes the interval [begin, end] hold the next permutation of the same elements else returns false
    //* Ensure that your container is sorted before calling next or prev permutation, initial state should be the very first permutation.
    std::vector<int> v1;
    for (int i = 0; i < 5; i++)
        v1.push_back(dist(mt));

    std::sort(v1.begin(), v1.end());
    std::cout << "\n";

    do
    {
        for (int i = 0; i < v1.size(); i++)
            std::cout << v1[i] << " ";
        std::cout << "\n";
    } while (next_permutation(v1.begin(), v1.end()));

    //! prev_permutation() : holds the previous permutation of the same elements.
}

void copy()
{
    std::vector<int> v1;
    std::vector<int> v2;

    std::mt19937 mt(60);
    std::uniform_int_distribution dist(100, 1000);

    for (int i = 0; i < 10; i++)
        v1.push_back(dist(mt));
    for (int i = 0; i < 15; i++)
        v2.push_back(dist(mt));

    // ensure v1 has enough space
    v1.resize(v1.size() + v2.size());
    // copy v2 elements right after v1, cause it has expanded
    std::copy(v2.begin(), v2.end(), v1.end() - v2.size());
}

// @param begin-iterator
// @param end-iterator
// @param initial-value-and-typeof
// @param predicate
// @returns value after algebraic operations on a container
void accumulate()
{
    std::mt19937 mt(60);
    std::uniform_int_distribution dist(100, 1000);
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(dist(mt));
    int sum = std::accumulate(all(v), 0);
    double product = std::accumulate(all(v), double(1), std::multiplies<double>());
}

// @param begin1 beginning itr of first container
// @param end1 ending itr of first container
// @param begin2 beginning itr of second container
// @param init initial value of accumulator and type
void inner_product()
{
    std::mt19937 mt(60);
    std::uniform_int_distribution dist(100, 1000);
    std::vector<int> v1;
    std::vector<int> v2;
    fr(i, 13)
    {
        v1.pb(dist(mt));
        v2.pb(dist(mt));
    }
    int r = std::inner_product(all(v1), v2.begin(), 0);
    int rRev = std::inner_product(all(v1), v2.rbegin(), 0);
    // this needs only increment operators, so normal itr are enough

    std::set<int> values_ordered_data(all(v1));
    int n = sz(v1);
    std::vector<int> convolution_kernel(n);
    fr(i, n)
        convolution_kernel[i] = (i + 1) * (n - 1);
    double result = double(std::inner_product(all(values_ordered_data), convolution_kernel.begin(), 0) / std::accumulate(all(convolution_kernel), 0));
}
