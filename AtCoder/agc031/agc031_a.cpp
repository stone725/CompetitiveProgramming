#include <iostream>
#include <string>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt[26];
    for (int i = 0; i < 26; i++)
    {
        cnt[i] = 1;
    }
    for (auto &&i : str)
    {
        cnt[i - 'a']++;
    }
    long long ans = 1;
    for (auto &&i : cnt)
    {
        ans *= i;
        ans %= INF;
    }
    cout << ans - 1 << "\n";
}