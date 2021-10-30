#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <algorithm>
// #include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define endl "\n"
using namespace std;

int mergeSort(int *, int, int);
int merge(int *, int, int, int);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    fr(i, n)
            cin >>
        arr[i];
    mergeSort(arr, 0, n - 1);
    fr(i, n)
            cout
        << arr[i] << " ";
    return 0;
}

int mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int merge(int *arr, int start, int mid, int end)
{
    // building a tmp array to avoid modifying the contents of original arr.
    int tmp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    // while both sub-array have values
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            i++, k++;
        }
        else
        {
            tmp[k] = arr[j];
            j++, k++;
        }
    }
    // add the rest of values of left subarray in result
    while (i <= mid)
    {
        tmp[k] = arr[i];
        i++, k++;
    }
    // add the rest of values of right subarray in result
    while (j <= end)
    {
        tmp[k] = arr[j];
        j++, k++;
    }
    for (i = start; i <= end; i++)
    {
        // overriding values to the original array
        arr[i] = tmp[i - start];
    }
}