#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<int> p(n);
        for (auto &&i : p)
        {
            cin >> i;
        }
        vector<int> j(n - 1);
        for (auto &&i : j)
        {
            cin >> i;
        }
        long long sumsize = accumulate(begin(p), end(p), 0);
        long long ans = sumsize * n;
        sort(rbegin(j), rend(j));
        for (int i = 0; i < n - 1; i++)
        {
            sumsize += j[i];
            ans = max(ans, sumsize * (n - 1 - i));
        }
        cout << ans << "\n";
    }
}