#include <bits/stdc++.h>
using namespace std;
#define int long long
int check(int y)
{
    int sum = 0;
    int temp = y;
    while (y > 0)
    {
        sum += y % 10;
        y = y / 10;
    }
    return temp - sum;
}
void solve(int n, int s)
{
    int lo = 1;
    int hi = n;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int k = check(mid);
        if (k >= s)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (ans == -1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << (n - ans + 1) << "\n";
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        solve(n, s);
    }
}