#include <iostream>
#include <vector>
#include <algorithm>

struct Weighted_Union_Find
{
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<long long> wdiff;
    //初期化
    void init(int n)
    {
        par.resize(n);
        rank.resize(n);
        wdiff.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
            rank[i] = 0;
            wdiff[i] = 0;
        }
    }

    //木の根を探す
    int find(int s)
    {
        if (par[s] == s)
        {
            return s;
        }
        int r = find(par[s]);
        wdiff[s] += wdiff[par[s]];
        return par[s] = r;
    }

    long long weight(int x)
    {
        find(x); // 経路圧縮
        return wdiff[x];
    }

    long long diff(int x, int y)
    {
        return weight(y) - weight(x);
    }

    //結合
    bool unite(int x, int y, long long w)
    {
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        if (rank[x] < rank[y])
        {
            std::swap(x, y);
            w = -w;
        }
        if (rank[x] == rank[y])
            ++rank[x];
        par[y] = x;
        wdiff[y] = w;
        return true;
    }

    //二つの数の根が同じかどうか
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    //サイズを返す
    unsigned int size()
    {
        return par.size();
    }
};

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    Weighted_Union_Find wuf;
    while (cin >> n >> q && n && q)
    {
        wuf.init(n);
        while (q--)
        {
            char query;
            cin >> query;
            if (query == '!')
            {
                int a, b, w;
                cin >> a >> b >> w;
                wuf.unite(a - 1, b - 1, w);
            }
            else
            {
                int a, b;
                cin >> a >> b;
                if (wuf.same(a - 1, b - 1))
                {
                    cout << wuf.diff(a - 1, b - 1) << "\n";
                }
                else
                {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}