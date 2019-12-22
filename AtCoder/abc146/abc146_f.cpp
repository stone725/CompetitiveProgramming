#include <iostream>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string str;
    set<int> canmove;
    cin >> n >> m;
    cin >> str;
    if (str.find(string(m, '1')) != string::npos)
    {
        cout << "-1\n";
        return 0;
    }
    if (m == 1)
    {
        string ans = "1";
        for (int i = 1; i < n; i++)
        {
            ans += " 1";
        }
        cout << ans << "\n";
        return 0;
    }
    for (int i = 0; i <= n; i++)
    {
        if (str[i] == '1')
            continue;
        canmove.insert(i);
    }
    map<int, int> tomove;
    auto ep = end(canmove);
    list<int> ans;
    int p = n;
    while (p > 0)
    {
        auto bp = canmove.lower_bound(p - m);
        ans.push_front(p - *bp);
        p = *bp;
        canmove.erase(bp, canmove.end());
    }
    while (ans.size() > 1)
    {
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << ans.back() << "\n";
}