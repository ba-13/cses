#include <ctime>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int main()
{
    int n;
    std::cin >> n;
    vi numbers(n);
    fr(i, n) std::cin >> numbers[i];
    return 0;
}