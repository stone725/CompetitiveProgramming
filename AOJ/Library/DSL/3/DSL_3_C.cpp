#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    while (q--)
    {
        long long x;
        cin >> x;
        long long s = 0, g = 0, score = 0;
        long long ans = 0;
        while (g < n)
        {
            score += a[g];
            while (x < score)
            {
                ans += g - s;
                score -= a[s];
                s++;
            }
            g++;
        }
        while (s < g)
        {
            ans += g - s;
            s++;
        }
        cout << ans << "\n";
    }
}