#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int INF = 1e9 + 7;

int n, a, b, c;
vector<int> l;

int dfs(int now, int A, int B, int C)
{
    if (now == n)
    {
        return !A || !B || !C ? INF : abs(A - a) + abs(B - b) + abs(C - c);
    }
    int res = dfs(now + 1, A, B, C);
    res = min(res, dfs(now + 1, A + l[now], B, C) + (A ? 10 : 0));
    res = min(res, dfs(now + 1, A, B + l[now], C) + (B ? 10 : 0));
    res = min(res, dfs(now + 1, A, B, C + l[now]) + (C ? 10 : 0));
    return res;
}

int main()
{
    cin >> n >> a >> b >> c;
    l.resize(n);
    for (auto &&i : l)
    {
        cin >> i;
    }
    cout << dfs(0, 0, 0, 0) << "\n";
}