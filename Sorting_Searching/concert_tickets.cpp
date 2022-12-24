#include <ctime>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <set>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int main()
{
    int n_tickets, m_customers;
    std::cin >> n_tickets >> m_customers;
    std::multiset<int> tickets;
    std::vector<int> customers(m_customers);
    fr(i, n_tickets)
    {
        int tmp;
        std::cin >> tmp;
        tickets.insert(tmp);
    }
    fr(i, m_customers) std::cin >> customers[i];
    fr(i, m_customers)
    {
        auto itr = tickets.lower_bound(customers[i]);
        if (*itr != customers[i])
        {
            if (itr == tickets.begin()) // no answer exists
            {
                std::cout << -1 << "\n";
                continue;
            }
            else // answer is one before
            {
                itr--;
            }
        }
        std::cout << *(itr) << "\n";
        tickets.erase(itr);
    }
    return 0;
}