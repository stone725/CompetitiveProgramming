#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static const int INF = 1e9 + 7;

int n, k;
bool canuse[10];
vector<int> useInts;

int dfs(int now, int score)
{
    if (now < 0)
        return INF;
    if (score >= n)
        return score;
    int res = INF;
    for (auto &&i : useInts)
    {
        res = min(res, dfs(now - 1, score * 10 + i));
    }
    return res;
}

int main()
{
    cin >> n >> k;
    for (auto &&i : canuse)
    {
        i = true;
    }
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        canuse[d] = false;
    }
    for (int i = 0; i < 10; i++)
    {
        if (canuse[i])
        {
            useInts.push_back(i);
        }
    }
    int size = to_string(n).size();
    cout << dfs(size + 1, 0) << "\n";
}