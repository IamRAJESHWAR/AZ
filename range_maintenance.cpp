#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> ii;
    vector<int> l, r;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ii.insert({a, b});
        l.push_back(a);
        r.push_back(b);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;

        int lcount = l.size() - (upper_bound(l.begin(), l.end(), k) - l.begin());
        int rcount = lower_bound(r.begin(), r.end(), k) - r.begin();

        cout << (l.size() - (lcount + rcount));
    }
}
