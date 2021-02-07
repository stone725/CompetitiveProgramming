#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<unsigned long long> p[26];
    for (int i = 0; i < s.size(); i++)
    {
        p[s[i] - 'a'].push_back(i + 1);
    }
    unsigned long long ans = 0;
    string t;
    cin >> t;
    for (auto &&i : t)
    {
        if (p[i - 'a'].empty())
        {
            cout << "-1\n";
            return 0;
        }
        auto point = upper_bound(begin(p[i - 'a']), end(p[i - 'a']), ans % s.size());
        if (point == end(p[i - 'a']))
        {
            point = upper_bound(begin(p[i - 'a']), end(p[i - 'a']), 0);
            ans += s.size();
        }
        ans /= s.size();
        ans *= s.size();
        ans += *point;
    }
    cout << ans << "\n";
}