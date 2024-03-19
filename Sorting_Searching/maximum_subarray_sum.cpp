#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll int64_t
#define vi std::vector<int>

int main()
{
    int n;
    std::cin >> n;
    vi numbers(n);
    fr(i, n) std::cin >> numbers[i];
    ll running_sum = 0;
    int length = 0;
    ll max_sum = INT64_MIN;
    fr(i, n)
    {
        // consider all maximum subarrays that end at i
        // and keep a track of the running sum
        if (running_sum + numbers[i] >= 0)
        {
            // if the sum remains greater than 0 after adding, keep it
            running_sum += numbers[i];
            length += 1;
        }
        else
        {
            // else restart from the next i + 1
            running_sum = 0;
            length = 0;
        }

        if (running_sum > max_sum && length > 0)
            // find the max of these sums
            max_sum = running_sum;
    }
    if (max_sum == INT64_MIN)
    {
        std::vector<int>::iterator val = std::max_element(numbers.begin(), numbers.end());
        max_sum = *val;
    }
    std::cout << max_sum << endl;
    return 0;
}