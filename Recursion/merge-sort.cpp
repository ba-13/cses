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

int mergeSort(int, int *);
int merge(int *, int *, int *, int, int);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    fr(i, n)
            cin >>
        arr[i];
    mergeSort(n, arr);
    fr(i, n)
            cout
        << arr[i] << " ";
    return 0;
}

int mergeSort(int n, int *arr)
{
    // a base case for splitting the arrays
    if (n < 2)
        return 0;

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    // effectively splitting the array by copying its contents to two new arrays
    // original array isn't tampered with yet.
    fr(i, mid)
        left[i] = arr[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    // split the left and the right arrays themselves, merge them while sorting
    // again, you called upon the subproblems' solutions, and later provide them the means to get the solution (line 58)
    // assume you have the answer, then provide the answer's way
    mergeSort(mid, left);
    mergeSort(n - mid, right);

    // obtain the sorted array by merging two sorted sub-arrays
    merge(left, right, arr, n, mid);
    return 0;
}

int merge(int *left, int *right, int *arr, int n, int mid)
{
    // declare pointer-like indices to keep track of which should be filled where.
    int i = 0;
    int j = 0;
    int k = 0;

    int lenL = mid;
    int lenR = n - mid;

    // till both arrays compete to be filled in
    while (i < lenL && j < lenR)
    {
        // check if ith index of left should be fitted
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        // check if the jth index of right should be fitted
        else if (right[j] <= left[i])
        {
            arr[k] = right[j];
            j++;
        }
        // at least one of them has been fitted
        k++;
    }

    // the rest of the left-over array should just be filled in.

    while (i < lenL)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < lenR)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return 0;
}