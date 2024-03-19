#include <algorithm>
#include <iostream>
#include <limits.h>
#include <random>
#include <vector>
const int debugging = false;
#define deb(x)     \
    if (debugging) \
        std::cout << #x << " : " << x << "\n";
#define fr(i, n) for (int i = 0; i < n; i++)
#define vi std::vector<int>

int minAppleDivisionSlow(std::vector<long long> &apples);
int minAppleDivisionFast(std::vector<long long> &apples);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    if (debugging)
        std::cout << ">>>\n";

    int n = INT_MAX;
    std::cin >> n;
    std::vector<long long> apples(n);
    fr(i, n) std::cin >> apples[i];
    // int minimum = minAppleDivisionSlow(apples);
    // std::cout << minimum;
    int minimum = minAppleDivisionFast(apples);
    std::cout << minimum;
    return 0;
}

int minAppleDivisionSlow(std::vector<long long> &apples)
{
    int n = apples.size();
    std::sort(apples.begin(), apples.end());
    long long totalSum = 0;
    totalSum = std::accumulate(apples.begin(), apples.end(), totalSum);
    if (n == 1)
    {
        std::cout << apples[0];
        return 0;
    }
    int min = 1e9;
    do
    {
        for (int i = 0; i < n; i++)
        {
            long long sum1 = 0, sum2 = 0;
            int diff = totalSum - 2 * std::accumulate(apples.begin() + i, apples.end(), sum2);
            diff = diff > 0 ? diff : -diff;
            if (min > diff)
                min = diff;
        }
    } while (next_permutation(apples.begin(), apples.end()));

    return min;
}

int minAppleDivisionFast(std::vector<long long> &apples)
{
    /**
     * This is the method of creating subsequences using bits
     * Like, let the array from which we need to get subsequences is
     * 2 3 4 1
     * Represent this as 0000, in that order, thus there are 15 possible subsequences.
     * 0010 means 4
     * 1110 means 2 3 4
     * 1001 means 2 1
     * and so on
     */
    int n = apples.size();
    long long totalSum = 0;
    totalSum = std::accumulate(apples.begin(), apples.end(), totalSum);
    deb(totalSum);
    long long minSubSum = LONG_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        long long subSum1 = 0;
        long long subSum2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                subSum1 += apples[j];
            else
                subSum2 += apples[j];
        }
        deb(subSum1);
        long long min = subSum1 > subSum2 ? subSum1 - subSum2 : subSum2 - subSum1;
        if (min < minSubSum)
            minSubSum = min;
    }

    return minSubSum;
}