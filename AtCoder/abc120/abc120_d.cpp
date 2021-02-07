#include <iostream>
#include <vector>
#include <utility>

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

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    Union_Find uf;
    uf.init(n);
    vector<pair<int, int>> p(m);
    for (auto &&i : p)
    {
        cin >> i.first >> i.second;
        i.first--;
        i.second--;
    }
    vector<long long> ans(m);
    ans[m - 1] = n * (n - 1) / 2;
    for (long long i = m - 1; i > 0; i--)
    {
        if (uf.same(p[i].first, p[i].second))
        {
            ans[i - 1] = ans[i];
        }
        else
        {
            ans[i - 1] = ans[i] - uf.size(p[i].first) * uf.size(p[i].second);
            uf.unite(p[i].first, p[i].second);
        }
    }
    for (auto &&i : ans)
    {
        cout << i << "\n";
    }
}