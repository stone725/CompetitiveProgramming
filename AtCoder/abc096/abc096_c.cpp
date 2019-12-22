#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> paper(h);
    for (auto &&i : paper)
    {
        cin >> i;
    }
    const int dx[] = {0, -1, 0, 1};
    const int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (paper[i][j] == '#')
            {
                bool finish = true;
                for (int k = 0; k < 4; k++)
                {
                    if (i + dx[k] < 0 || i + dx[k] == h || j + dy[k] < 0 || j + dy[k] == w)
                    {
                        continue;
                    }
                    if (paper[i + dx[k]][j + dy[k]] == '#')
                    {
                        finish = false;
                        break;
                    }
                }
                if (finish)
                {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";
}