#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<int> h;

bool dfs(int now, int many)
{
    if (now == n - 1)
        return true;
    if (h[now + 1] - h[now] > many + k)
        return false;
    if (max(0, h[now + 1] - k) <= h[now])
    {
        return dfs(now + 1, many + h[now] - max(0, h[now + 1] - k));
    }
    return dfs(now + 1, many - (h[now + 1] - k - h[now]));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        h.resize(n);
        for (auto &&i : h)
        {
            cin >> i;
        }
        if (dfs(0, m))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}