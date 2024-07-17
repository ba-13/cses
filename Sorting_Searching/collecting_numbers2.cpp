/*
* @Author: ba13
* @Date:   2024-07-18 02:20:40
* @Last Modified by:   ba13
* @Last Modified time: 2024-07-18 02:25:02
INCOMPLETE for now
*/
#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int n{}, m{};
    std::cin >> n >> m;
    std::vector<int> input(n);
    std::vector<std::pair<int, int>> swaps(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        swaps[i] = {a - 1, b - 1};
    }
    return 0;
}