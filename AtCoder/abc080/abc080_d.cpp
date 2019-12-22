#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<vector<pair<int, int>>> ch(c);
    for (int i = 0; i < n; i++)
    {
        int s, t, cnum;
        cin >> s >> t >> cnum;
        cnum--;
        ch[cnum].push_back(make_pair(s, t));
    }
    vector<vector<pair<int, int>>> ch2(c);
    vector<pair<int, int>> rec;
    for (int i = 0; i < c; i++)
    {
        sort(begin(ch[i]), end(ch[i]));
        for (auto &&j : ch[i])
        {
            if (ch2[i].empty())
            {
                ch2[i].push_back(j);
                continue;
            }
            if (rbegin(ch2[i])->second == j.first)
            {
                rbegin(ch2[i])->second = j.second;
            }
            else
            {
                ch2[i].push_back(j);
            }
        }
        rec.insert(end(rec), begin(ch2[i]), end(ch2[i]));
    }
    sort(begin(rec), end(rec));
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &&i : rec)
    {
        if (q.empty())
        {
            q.push(i.second);
            continue;
        }
        if (q.top() < i.first)
        {
            q.pop();
        }
        q.push(i.second);
    }
    cout << q.size() << "\n";
}