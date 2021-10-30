#include <iostream>
#include <random>
#include <vector>
#include <map>
#define deb(x) std::cout << #x << " : " << x << "\n";

bool canSum(int, std::vector<int> &, std::map<int, bool> &);

int main()
{
    std::mt19937 mt(1002);
    std::uniform_int_distribution<int> dist(13, 30);
    int targetSum, n;
    std::cin >> targetSum;
    std::cin >> n;
    std::vector<int> arr(n);
    std::map<int, bool> memo;

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    // arr[i] = dist(mt);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\nPattern to follow: ";
    std::cout << "\n--- " << canSum(targetSum, arr, memo);
    return 0;
}

bool canSum(int targetSum, std::vector<int> &v, std::map<int, bool> &memo)
{
    if (memo.find(targetSum) != memo.end())
        return memo[targetSum];
    if (!targetSum)
    {
        std::cout << targetSum << " ";
        return true;
    }
    else if (targetSum < 0)
    {
        return false;
    }
    for (int i = 0; i < v.size(); i++)
    {
        int tmp = targetSum - v[i];
        if (canSum(tmp, v, memo))
        {
            std::cout << targetSum << " ";
            memo[tmp] = true;
            return true;
        }
    }
    return false; // as none of its child matters
}