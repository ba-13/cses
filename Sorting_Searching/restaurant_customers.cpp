#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
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
    std::vector<std::pair<int, int>> customers(n);
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;

    fr(i, n) std::cin >> customers[i].first >> customers[i].second;
    std::sort(
        customers.begin(), customers.end(),
        [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool
        { return a.first < b.first; });

    int currTime = customers[0].first;
    int currCustomers = 0, result = 0;
    fr(i, n)
    {
        currTime = customers[i].first;
        q.push(customers[i].second);
        currCustomers++;
        while (!q.empty() and q.top() <= currTime)
        {
            q.pop();
            currCustomers--;
        }
        result = std::max(currCustomers, result);
    }
    std::cout << result << "\n";
    return 0;
}