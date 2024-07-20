#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <utility>
#include <vector>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> movies(n);
    fr(i, n) std::cin >> movies[i].first >> movies[i].second;
    std::sort(movies.begin(), movies.end(),
              [](const std::pair<int, int> &a, std::pair<int, int> &b) -> bool
              { return a.second < b.second; });

    int result = 0;
    int currEndTime = -1;
    for (auto movie : movies)
    {
        if (movie.first >= currEndTime)
        {
            result++;
            currEndTime = movie.second;
        }
    }
    std::cout << result << "\n";

    return 0;
}