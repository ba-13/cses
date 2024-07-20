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
    int n, target;
    std::cin >> n >> target;
    std::vector<std::pair<int, int>> numbers(n);
    fr(i, n)
    {
        std::cin >> numbers[i].first;
        numbers[i].second = i;
    }
    std::sort(numbers.begin(), numbers.end());

    int l = 0, u = n - 1;
    int sum = 0;
    while (l < u)
    {
        sum = numbers[l].first + numbers[u].first;
        if (sum == target)
            break;
        else if (sum > target)
            u--;
        else if (sum < target)
            l++;
    }
    if ((l == u) or (numbers[l].first + numbers[u].first != target))
        std::cout << "IMPOSSIBLE";
    else
        std::cout << numbers[l].second + 1 << " " << numbers[u].second + 1
                  << "\n";
    return 0;
}