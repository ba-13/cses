#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <vector>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int gondolas_needed(int n, int x, std::vector<int> &weights)
{
    int result = 0;
    int light = n - 1, heavy = 0;
    while (heavy <= light) // irony
    {
        if (weights[heavy] + weights[light] <= x)
        {
            heavy++, light--;
        }
        else
        {
            heavy++;
        }
        result++;
    }
    // if (heavy == light)
    //     result++;

    return result;
}

int main()
{
    int n_children = -1, x_gondola_weight = -1;
    std::cin >> n_children >> x_gondola_weight;
    std::vector<int> weights(n_children);
    fr(i, n_children) std::cin >> weights[i];                       // 7 2 3 9
    std::sort(weights.begin(), weights.end(), std::greater<int>()); // 9 7 3 2

    int result = 0;

    if (*weights.begin() > x_gondola_weight)
        result = -1;
    else
        result = gondolas_needed(n_children, x_gondola_weight, weights);

    std::cout << result << "\n";

    return 0;
}