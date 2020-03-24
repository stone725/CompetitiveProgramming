#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, long long> cnt;
    for (auto &&i : a)
    {
        cin >> i;
        cnt[i]++;
    }
    long long ans = 0;
    for (auto &&i : cnt)
    {
        ans += i.second * (i.second - 1) / 2;
    }
    for (auto &&i : a)
    {
        cout << ans - cnt[i] + 1 << "\n";
    }
}