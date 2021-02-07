#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> field;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

int dfs(int x, int y)
{
    if (x < 0 || y < 0 || x == n || y == m || field[x][y] == '.')
    {
        return 0;
    }
    field[x][y] = '.';
    for (int i = 0; i < 8; i++)
    {
        dfs(x + dx[i], y + dy[i]);
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    field.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> field[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += dfs(i, j);
        }
    }
    cout << ans << "\n";
}