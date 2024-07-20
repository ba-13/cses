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

using namespace std;

int main()
{
    int n, tmp;
    std::cin >> n;
    std::set<int> s_;
    fr(i, n)
    {
        std::cin >> tmp;
        s_.insert(tmp);
    }
    std::cout << s_.size() << "\n";
    return 0;
}