#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2)
            n = 3 * n + 1;
        else
            n = n / 2;
    }
    cout << n;
    return 0;
}