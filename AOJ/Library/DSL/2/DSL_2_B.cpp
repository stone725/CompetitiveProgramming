#include <iostream>
#include <vector>
#include <algorithm>

struct RangeSumQuery
{
    int n;
    std::vector<long long> dat;

    void init(int n_)
    {
        n = 1;
        while (n < n_)
            n *= 2;
        dat.resize(2 * n - 1, 0);
    }

    long long sum(int i)
    {
        long long s = 0;
        while (i > 0)
        {
            s += dat[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x)
    {
        while (i <= n)
        {
            dat[i] += x;
            i += i & -i;
        }
    }

    long long sum(int a, int b)
    {
        return sum(b) - sum(a - 1);
    }
};

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    RangeSumQuery rsq;
    rsq.init(n);
    while (q--)
    {
        int com, x, y;
        cin >> com >> x >> y;
        if (com)
        {
            cout << rsq.sum(x, y) << "\n";
        }
        else
        {
            rsq.add(x, y);
        }
    }
}