// #include <iostream>
// #include <vector>
// #include <algorithm>
#include "macro.hpp"
const bool debugging = true;

/**
 * set_union
 * set_intersection
 * set_difference
 * set_symmetric_difference
 *
 * O(N1 + N2) time complexity
 * require the containers to be sorted
 *
 * prototype: end_result = set_intersection(begin1, end1, begin2, end2, begin_result);
 * size of result is unknown, so function returns end_result_iterator
 */

//@param from_begin1 first container's begin-ptr
//@param from_end1 first container's end-ptr
//@param from_begin2 second container's begin-ptr
//@param from_end2 second container's end-ptr
//@param to_start container where intersection has to be inserted
int set_intersection()
{
    int data1[10];
    for (int i = 0; i < 10; i++)
        data1[i] = i + 1;
    int data2[6];
    for (int i = 0; i < 6; i++)
        data2[i] = 2 * i;
    std::vector<int> v1(data1, data1 + sizeof(data1) / sizeof(data1[0]));
    show(v1);
    std::vector<int> v2(data2, data2 + sizeof(data2) / sizeof(data2[0]));
    show(v2);
    std::vector<int> tmp(std::max(v1.size(), v2.size()));
    show(tmp);
    std::vector<int> res(1);
    res = std::vector<int>(tmp.begin(), std::set_intersection(all(v1), all(v2), tmp.begin()));
    // tmp changes by set_intersection, and it's endptr is returned, thus giving a range for ptr allocation to res
    show(res);
}

int main()
{
    set_intersection();
    return 0;
}