/*
* @Author: ba13
* @Date:   2024-07-18 02:20:40
* @Last Modified by:   ba-13
* @Last Modified time: 2024-07-20 23:42:36
https://cses.fi/problemset/task/2217
Number of inversions in the position array is the answer we need
*/

#ifdef LOCAL
#include "../_header.hpp"
#else
#include <bits/stdc++.h>
#define deb(x) ;
#endif
using namespace std;

int main()
{
    int n{}, m{};
    std::cin >> n >> m;
    std::vector<int> input(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        std::cin >> input[i];
    }

    std::vector<std::pair<int, int>> swaps(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        swaps[i] = {a, b};
    }

    // count number of inversions in the position array
    vector<int> position(n + 1);
    for (int i = 1; i <= n; i++)
    {
        position[input[i]] = i;
    }
    int num_rounds = 1;
    for (int i = 1; i < n; i++)
    {
        int num_inversions = position[i] > position[i + 1];
        num_rounds += num_inversions;
    }
    deb(position);
    deb(num_rounds);

    set<pair<int, int>> updatedPairs;
    for (int i = 0; i < m; i++)
    {
        int l = swaps[i].first, r = swaps[i].second;
        // input[l] and its neighbors input[l]-1 and input[l]+1
        // these values positions in position array decides the inversions
        if (input[l] - 1 >= 1)
            updatedPairs.insert({input[l] - 1, input[l]});
        if (input[l] + 1 <= n)
            updatedPairs.insert({input[l], input[l] + 1});
        if (input[r] - 1 >= 1)
            updatedPairs.insert({input[r] - 1, input[r]});
        if (input[r] + 1 <= n)
            updatedPairs.insert({input[r], input[r] + 1});

        deb(updatedPairs);
        // before swap, count inversions
        for (pair<int, int> check : updatedPairs)
        {
            int num_inversions = position[check.first] > position[check.second];
            num_rounds -= num_inversions;
        }

        // now swap in the original array
        swap(input[l], input[r]);

        // update position array, note that input[l] = r after swap
        position[input[l]] = l;
        position[input[r]] = r;

        // after swap, update inversions
        for (pair<int, int> check : updatedPairs)
        {
            int num_inversions = position[check.first] > position[check.second];
            num_rounds += num_inversions;
        }
        std::cout << num_rounds << "\n";
        updatedPairs.clear();
    }
    return 0;
}