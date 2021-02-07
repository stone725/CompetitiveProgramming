#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    int ans = 1e9 + 7;
    for (int i = 1; i <= 100; i++)
    {
        int score = 0;
        for (auto &&j : a)
        {
            score += (j - i) * (j - i);
        }
        ans = min(score, ans);
    }
    cout << ans << "\n";
}