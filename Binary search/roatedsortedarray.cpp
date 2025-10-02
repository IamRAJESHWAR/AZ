/*
Problem Statement: Given a rotated sorted array with distinct elements, find the index of the minimum element in the array.

*/

#include <bits/stdc++.h>
using namespace std;
int check(int mid, int arr[], int n)
{
    if (mid == n - 1)
        return 1;
    if (arr[mid] < arr[0])
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lo = 0;
    int high = n - 1;
    int ans = -1;

    while (lo <= high)
    {
        int mid = (lo + high) / 2;
        if (check(mid, arr, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans;
}