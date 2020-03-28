#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Union_Find
{
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> sz;
    //初期化
    void init(int n)
    {
        par.resize(n);
        rank.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }

    //木の根を探す
    int find(int s)
    {
        if (par[s] == s)
        {
            return s;
        }
        return par[s] = find(par[s]);
    }

    //結合
    void unite(int x, int y)
    {
        int a = find(x), b = find(y);
        if (a == b)
        {
            return;
        }
        int size = sz[a] + sz[b];
        sz[a] = sz[b] = size;
        if (rank[a] < rank[b])
        {
            par[a] = b;
        }
        else
        {
            par[a] = b;
            if (rank[a] == rank[b])
            {
                ++rank[b];
            }
        }
    }

    //二つの数の根が同じかどうか
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    //サイズを返す
    int size(int n)
    {
        return sz[find(n)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    Union_Find uf;
    uf.init(n);
    vector<int> ans(n, -1);
    vector<set<int>> friends(n);
    vector<set<int>> guard(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[min(a - 1, b - 1)].insert(max(a - 1, b - 1));
        uf.unite(a - 1, b - 1);
        ans[a - 1]--;
        ans[b - 1]--;
    }
    for (int i = 0; i < k; i++)
    {
        int c, d;
        cin >> c >> d;
        guard[min(c - 1, d - 1)].insert(max(c - 1, d - 1));
        if (uf.same(c - 1, d - 1))
        {
            ans[c - 1]--;
            ans[d - 1]--;
        }
    }
    cout << ans[0] + uf.size(0);
    for (int i = 1; i < n; i++)
    {
        cout << " " << ans[i] + uf.size(i);
    }
    cout << "\n";
}