/*Range Maintenance Ideas - 1
Problem Statement:
We are given N ranges varies from Li to Ri on number line. Then you are given Q queries in form of ? Y, which means you have to return how many ranges passes through this points. Constraints N, Q <=1e5 Li, Ri, Y <=1e9

Approach:
To efficiently solve the problem of counting the number of ranges that pass through a given point Y, we can use a binary search-based approach. We'll preprocess the given ranges to sort them based on their left and right endpoints. Then, for each query point Y, we'll use binary search to find the number of ranges that pass through Y.

Here's the detailed approach:

Sort the given ranges based on their left endpoints.
For each query point Y:
Perform a binary search to find the number of ranges whose right endpoint is less than Y (i.e., ranges ending before Y). This can be done using the lower_bound function in C++ or the bisect_left function in Python.
Perform a binary search to find the number of ranges whose left endpoint is greater than Y (i.e., ranges starting after Y). This can be done using the upper_bound function in C++ or the bisect_right function in Python.
The total number of ranges passing through Y is given by: Total ranges - (number of ranges ending before Y + number of ranges starting after Y).*/

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
