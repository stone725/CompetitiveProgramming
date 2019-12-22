#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

int main()
{
    static const int dx[] = {0, 1, 0, -1};
    static const int dy[] = {1, 0, -1, 0};
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    vector<vector<int>> check(h, vector<int>(w, -1));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < h; i++)
    {
        cin >> c[i];
        for (int j = 0; j < w; j++)
        {
            if (c[i][j] == 's')
            {
                q.push(make_tuple(i, j, 2));
            }
        }
    }
    while (q.size())
    {
        auto status = q.front();
        q.pop();
        int x = get<0>(status), y = get<1>(status), cnt = get<2>(status);
        if (cnt <= check[x][y])
        {
            continue;
        }
        check[x][y] = cnt;
        if (c[x][y] == 'g')
        {
            cout << "YES\n";
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] == h || y + dy[i] < 0 || y + dy[i] == w)
            {
                continue;
            }
            if (cnt - (c[x + dx[i]][y + dy[i]] == '#') <= check[x + dx[i]][y + dy[i]])
            {
                continue;
            }
            q.push(make_tuple(x + dx[i], y + dy[i], cnt - (c[x + dx[i]][y + dy[i]] == '#')));
        }
    }
    cout << "NO\n";
}