// finding of extendible period and normal period
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int kmp[n + 1];
    int i = 0, j = -1;
    kmp[0] = -1;

    while (i < n)
    {
        while (j != -1 && s[i] != s[j])
            j = kmp[j];
        i++;
        j++;
        kmp[i] = j;
    }
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << n - kmp[n];
    }
    if (k == 2)
    {
        int r = n % (n - kmp[n]);
        if (r == 0)
        {
            cout << n - kmp[n];
        }
        else
        {
            cout << n;
        }
    }
}