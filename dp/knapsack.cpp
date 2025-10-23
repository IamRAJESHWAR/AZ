#include <bits/stdc++.h>
using namespace std;
vector<int> solution;
vector<int> x;
vector<int> v;
int n;
int w;
int dp[1000][1000];

int rec(int level, int wleft)
{
    if (level == n)
        return 0;
    if (dp[level][wleft] != -1)
        return dp[level][wleft];
    int ans = rec(level + 1, wleft);

    if (x[level] <= wleft)
    {
        ans = max(ans, v[level] + rec(level + 1, wleft - x[level]));
    }
    return dp[level][wleft] = ans;
}

void generate(int level, int wleft)
{
    if (level == n)
        return;

    int donttake = rec(level + 1, wleft);

    if (wleft >= x[level])
    {
        int take = v[level] + rec(level + 1, wleft - x[level]);

        if (donttake > take)
        {
            generate(level + 1, wleft);
        }
        else
        {
            solution.push_back(level);
            generate(level + 1, wleft - x[level]);
        }
    }
    else
    {
        generate(level + 1, wleft);
    }
}

int main()
{
    cin >> n;
    cin >> w;
    x.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    rec(0, w);
    generate(0, w);
    for (auto v : solution)
    {
        cout << v << " ";
    }
}
