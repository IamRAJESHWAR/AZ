#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> parent;
vector<int> depth;
void dfs(int node, int par, int dep)
{
    parent[node] = par;
    depth[node] = dep;
    for (auto v : g[node])
    {
        if (v != par)
        {
            dfs(v, node, dep + 1);
        }
    }
}

void solve(int n)
{

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);

    int maxch = 1;
    for (int j = 2; j <= n; j++)
    {
        if (depth[j] > depth[maxch])
        {
            maxch = j;
        }
    }
    dfs(maxch, 0, 0);
    maxch = 1;
    for (int j = 2; j <= n; j++)
    {
        if (depth[j] > depth[maxch])
        {
            maxch = j;
        }
    }
    cout << depth[maxch];
}

int main()
{
    int n;
    cin >> n;
    g.assign(n + 1, {});
    parent.assign(n + 1, 0);
    depth.assign(n + 1, 0);

    solve(n);
}