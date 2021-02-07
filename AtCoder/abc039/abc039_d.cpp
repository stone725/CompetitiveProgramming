#include <iostream>
#include <vector>

using namespace std;

int h, w;
vector<string> S;
vector<string> ans;
vector<string> anscheck;

bool check(int x, int y)
{
    const static int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    const static int dy[] = {-1, -1, -1, 1, 1, 1, 0, 0, 0};
    for (int i = 0; i < 9; i++)
    {
        if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] == h || y + dy[i] == w)
            continue;
        if (S[x + dx[i]][y + dy[i]] != '#')
            return false;
    }
    return true;
}

void draw(int x, int y)
{
    const static int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    const static int dy[] = {-1, -1, -1, 1, 1, 1, 0, 0, 0};
    for (int i = 0; i < 9; i++)
    {
        if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] == h || y + dy[i] == w)
            continue;
        anscheck[x + dx[i]][y + dy[i]] = '#';
    }
}

int main()
{
    cin >> h >> w;
    S.resize(h);
    for (auto &&i : S)
    {
        cin >> i;
    }
    ans.resize(h, string(w, '.'));
    anscheck.resize(h, string(w, '.'));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (S[i][j] == '#')
            {
                if (check(i, j))
                {
                    ans[i][j] = '#';
                }
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (ans[i][j] == '#')
            {
                draw(i, j);
            }
        }
    }
    if (anscheck == S)
    {
        cout << "possible\n";
        for (auto &&i : ans)
        {
            cout << i << "\n";
        }
    }
    else
    {
        cout << "impossible\n";
    }
}