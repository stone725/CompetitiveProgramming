#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> p[i];
    }
    vector<int> many(n, 1e9 + 7);
    for (int i = 0; i < m; i++)
    {
        int b, c;
        cin >> b >> c;
        many[b] = c;
        while (p[b])
        {
            many[p[b]] = min(many[p[b]], many[b]);
            b = p[b];
        }
    }
    long long ans = 0;
    many[0] = 0;
    for (int i = 1; i < n; i++)
    {
        ans += many[i] - many[p[i]];
    }
    cout << ans << "\n";
}