#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

int h, w;
vector<string> s;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main()
{
    cin >> h >> w;
    s.resize(h);
    for (auto &&i : s)
    {
        cin >> i;
    }
    set<tuple<int, int>> checked;
    int ans = 0;
    for (int sx = 0; sx < h; sx++)
    {
        for (int sy = 0; sy < w; sy++)
        {
            if (s[sx][sy] == '#')
                continue;
            checked.clear();
            queue<tuple<int, int, int>> q;
            q.push(make_tuple(sx, sy, 0));
            while (!q.empty())
            {
                auto status = q.front();
                int x = get<0>(status), y = get<1>(status), moved = get<2>(status);
                q.pop();
                if (checked.count(make_tuple(x, y)))
                {
                    continue;
                }
                checked.insert(make_tuple(x, y));
                ans = max(ans, moved);
                for (int i = 0; i < 4; i++)
                {
                    if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] == h || y + dy[i] == w)
                    {
                        continue;
                    }
                    if (s[x + dx[i]][y + dy[i]] == '#')
                    {
                        continue;
                    }
                    q.push(make_tuple(x + dx[i], y + dy[i], moved + 1));
                }
            }
        }
    }
    cout << ans << "\n";
}