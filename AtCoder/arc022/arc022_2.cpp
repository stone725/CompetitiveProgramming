#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    set<int> s;
    int l = 0, r = 0;
    int ans = 0;
    while (r < n)
    {
        if (l == r)
        {
            s.insert(a[r]);
            r++;
            ans = max<int>(ans, s.size());
            continue;
        }
        while (s.count(a[r]))
        {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        r++;
        ans = max<int>(ans, s.size());
    }
    cout << ans << "\n";
}