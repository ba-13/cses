/*
 * @Author: ba13
 * @Date:   2024-07-16 23:55:13
 * @Last Modified by:   ba-13
 * @Last Modified time: 2024-07-20 02:45:11
 */
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <set>
#include <stdlib.h>
#include <vector>

#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int using_set(vi &permutation)
{
    int n = permutation.size();
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
    return set_of_lowest.size();
}

int single_round_array_impl(std::vector<int> &input)
{
    int n = input.size();
    int answer = 1;
    std::vector<int> indices(n + 1);
    for (int i = 0; i < n; i++)
    {
        int val = input[i];
        indices[val] = i; // saving index
    }
    for (int i = 1; i < n; i++)
    {
        if (indices[i] > indices[i + 1])
            answer += 1;
    }
    return answer;
}

int main()
{
    int n;
    std::cin >> n;
    vi permutation(n);
    fr(i, n) std::cin >> permutation[i];
    int ans = using_set(permutation);
    std::cout << ans << "\n";
    return 0;
}