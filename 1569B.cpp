#include <iostream>
#include <vector>
using namespace std;

int solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcases;
    cin >> testcases;
    while (testcases--)
        solve();
    return 0;
}

int solve()
{
    int n;
    cin >> n;
    getchar(); //To consume "\n"
    string s;
    cin >> s;

    char result[n][n];
    for (int i = 0; i < n; i++)
    {
        char currExpectation = s[i];
        /**
         * if currExpectation is '1' => non-losing
         * if currExpectation is '2' => winning at least once
         */
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                result[i][j] == 'X';
                continue;
            }
            if (currExpectation == '1')
            {
                if (s[j] == '1')
                    result[i][j] = '=';
                else if (s[j] == '2')
                    result[i][j] = '=';
            }
            else if (currExpectation == '2')
            {
            }
        }
    }
}