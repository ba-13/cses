#include <iostream>
#include <random>
#include <vector>
#include <string>
const int debugging = true;
#define deb(x)     \
    if (debugging) \
        std::cout << #x << " : " << x << "\n";
#define fr(i, n) for (int i = 0; i < n; i++)
#define vi std::vector<int>

std::string board[8];

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    if (debugging)
        std::cout << ">>>\n";
    fr(i, 8) std::cin >> board[i];
    return 0;
}