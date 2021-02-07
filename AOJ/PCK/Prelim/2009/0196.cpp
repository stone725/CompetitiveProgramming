#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<tuple<char, int, int>> teams;
    while (cin >> n && n)
    {
        teams.resize(n);
        for (int i = 0; i < n; i++)
        {
            char team;
            cin >> team;
            int win = 0, lose = 0;
            for (int j = 0; j < n - 1; j++)
            {
                int result;
                cin >> result;
                switch (result)
                {
                case 0:
                    win++;
                case 1:
                    lose++;
                }
            }
            teams[i] = make_tuple(team, win, lose);
        }
        sort(begin(teams), end(teams), [](tuple<char, int, int> a, tuple<char, int, int> b) {
            if (get<1>(a) != get<1>(b))
            {
                return get<1>(a) > get<1>(b);
            }
            else
            {
                return get<2>(a) < get<2>(b);
            }
        });
        for (auto &&i : teams)
        {
            cout << get<0>(i) << "\n";
        }
    }
}