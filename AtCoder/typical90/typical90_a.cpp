#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int n, l, k;
vector<int> a;

bool check(const int mid)
{
    int before = 0, cnt = 0;
    for (auto &&i : a)
    {
        if (mid <= i - before)
        {
            cnt++;
            before = i;
        }
    }
    return k < cnt;
}

int main()
{
    cin >> n >> l;
    cin >> k;

    a.resize(n);

    for (auto &&i : a)
    {
        cin >> i;
    }

    a.push_back(l);

    int ok = 0, ng = l;

    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;

        if (check(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }

    cout << ok << "\n";
}