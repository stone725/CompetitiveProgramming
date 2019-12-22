#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    static const int INF = 1e9 + 7;
    int n;
    string s, t;
    long long dp[26] = {};
    cin >> n;
    cin >> s;
    cin >> t;
    dp[s[0] - 'a'] = 1;
    for (int i = 1; i < n - 1; i++)
    {
        dp[s[i] - 'a'] += dp[t[i] - 'a'];
        dp[s[i] - 'a'] %= INF;
    }
    cout << dp[t[n - 1] - 'a'] << "\n";
}