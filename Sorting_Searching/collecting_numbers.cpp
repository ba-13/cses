/*
* @Author: ba13
* @Date:   2024-07-16 23:55:13
* @Last Modified by:   ba13
* @Last Modified time: 2024-07-18 02:23:25
*/
#include <ctime>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int main()
{
    int n;
    std::cin >> n;
    vi permutation(n);
    fr(i, n) std::cin >> permutation[i];
    std::set<int> set_of_lowest;
    for (int i = 0; i < n; i++)
    {
        int curr = permutation[i];
        if (set_of_lowest.find(curr) != set_of_lowest.end())
        {
            // elongate this chain
            set_of_lowest.erase(curr);
        }
        set_of_lowest.insert(curr + 1);
    }
    std::cout << set_of_lowest.size() << "\n";
    return 0;
}