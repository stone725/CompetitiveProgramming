#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int INF = 1e9 + 7;

int n;
vector<vector<int>> b;

int dfs(int no)
{
    if (b[no].empty())
    {
        return 1;
    }
    int scoremin = INF, scoremax = 0;
    for (auto &&i : b[no])
    {
        int score = dfs(i);
        scoremin = min(scoremin, score);
        scoremax = max(scoremax, score);
    }
    return scoremin + scoremax + 1;
}

int main()
{
    cin >> n;
    b.resize(n);
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        b[num - 1].push_back(i);
    }
    cout << dfs(0) << "\n";
}