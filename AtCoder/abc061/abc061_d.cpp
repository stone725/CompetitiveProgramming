#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <limits>

using namespace std;

int n, m;
vector<tuple<int, int, long long>> edge;
vector<long long> d;

bool find_negative_loop()
{
    for (int i = 0; i < n; i++)
    {
        for (auto &&e : edge)
        {
            if (d[get<0>(e)] == -1e9 * n)
                continue;
            if (d[get<1>(e)] < d[get<0>(e)] + get<2>(e))
            {
                d[get<1>(e)] = d[get<0>(e)] + get<2>(e);
                if (i == n - 1)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    edge.resize(m);
    d.resize(n, -1e9 * n);
    d[0] = 0;
    for (auto &&i : edge)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a - 1 == 0)
        {
            d[b - 1] = c;
        }
        i = make_tuple(a - 1, b - 1, c);
    }
    if (find_negative_loop())
    {
        long long ans = d[n - 1];
        if (find_negative_loop() && ans != d[n - 1])
        {
            cout << "inf\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
    else
    {
        cout << d[n - 1] << "\n";
    }
}
