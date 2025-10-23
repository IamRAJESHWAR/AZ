// pattern matching

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string p, t;
    cin >> p >> t;
    string s = p + "#" + t;
    int n = s.length();
    int kmp[n + 1];
    int i = 0, j = -1;
    kmp[0] = -1;
    int d = p.length();
    while (i < n)
    {
        while (j != -1 && s[i] != s[j])
            j = kmp[j];
        i++;
        j++;
        kmp[i] = j;
    }
    for (auto v : kmp)
    {
        cout << v;
    }
    cout << "\n";
    int count = 0;
    for (auto v : kmp)
    {
        if (v == d)
        {
            count++;
        }
    }
    cout << count;
}