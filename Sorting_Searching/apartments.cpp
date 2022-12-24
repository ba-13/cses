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

using namespace std;

int main()
{
    int n_applicants, m_apartments, k_threshold;
    std::cin >> n_applicants >> m_apartments >> k_threshold;
    std::vector<int> desired_sizes(n_applicants), available_sizes(m_apartments);
    fr(i, n_applicants) std::cin >> desired_sizes[i];   // 60 45 80 60
    fr(i, m_apartments) std::cin >> available_sizes[i]; // 30 60 75

    std::sort(desired_sizes.begin(), desired_sizes.end());     // 45 60 60 80
    std::sort(available_sizes.begin(), available_sizes.end()); // 30 60 75

    int result = 0;
    int applicant = 0, apartment = 0;
    for (; applicant < n_applicants; applicant++)
    {
        while (available_sizes[apartment] <= k_threshold + desired_sizes[applicant])
        {
            if (apartment == m_apartments)
                break;
            if (available_sizes[apartment] <= desired_sizes[applicant] + k_threshold and available_sizes[apartment] >= desired_sizes[applicant] - k_threshold)
            {
                result++;
                apartment++;
                break;
            }
            else
                apartment++;
        }
    }
    std::cout << result << "\n";
    return 0;
}