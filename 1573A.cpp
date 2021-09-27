#include <iostream>
#include <vector>
using namespace std;

int solve();

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
        solve();
    return 0;
}

int solve()
{
    int n;
    cin >> n;
    int result = 0, tmp;
    getchar(); // Take up "\n"
    for (int i = 0; i < n; i++)
    {
        tmp = (int)(getchar() - '0');
        if (tmp != 0 && i != n - 1)
            result += tmp + 1;
        else if (tmp != 0 && i == n - 1)
            result += tmp;
    }
    cout << result << "\n";
}