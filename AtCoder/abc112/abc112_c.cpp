#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
vector<tuple<int, int, int>> p;

int check(int x, int y)
{
    int h = get<2>(p[0]) + abs(x - get<0>(p[0])) + abs(y - get<1>(p[0]));
    for (int i = 1; i < n; i++)
    {
        if (max(0, h - abs(x - get<0>(p[i])) - abs(y - get<1>(p[i]))) != get<2>(p[i]))
        {
            return 0;
        }
    }
    return h;
}

int main()
{
    cin >> n;
    p.resize(n);
    for (auto &&i : p)
    {
        int x, y, h;
        cin >> x >> y >> h;
        i = make_tuple(x, y, h);
    }
    int point = 0;
    while (!get<2>(p[point]))
        point++;
    swap(p[0], p[point]);
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            int score = check(i, j);
            if (0 < score)
            {
                cout << i << " " << j << " " << score << "\n";
                return 0;
            }
        }
    }
}