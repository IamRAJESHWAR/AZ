// find min no of characters to append at the end of the string . so the whole string after addition becomes a palindrome

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    string rev_s = s;
    string t;
    reverse(rev_s.begin(), rev_s.end());
    t = rev_s + "#" + s;
    int n = t.length();
    for (int i = 0; i < n; i++)
    {
        cout << t[i];
    }
    cout << "\n";

    int kmp[n + 1];
    int i = 0, j = -1;
    kmp[0] = -1;

    while (i < n)
    {
        while (j != -1 && t[i] != t[j])
            j = kmp[j];
        i++;
        j++;
        kmp[i] = j;
    }

    cout << len - kmp[n];
}