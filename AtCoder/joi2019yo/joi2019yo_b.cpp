#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool masu[2019] = {};
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &&i : x)
    {
        cin >> i;
        masu[--i] = true;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;
        if (x[a] + 1 == 2019 || masu[x[a] + 1])
        {
            continue;
        }
        masu[x[a]] = false;
        x[a]++;
        masu[x[a]] = true;
    }
    for (int i = 0; i < 2019; i++)
    {
        if (masu[i])
        {
            cout << i + 1 << "\n";
        }
    }
}