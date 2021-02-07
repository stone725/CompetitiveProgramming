#include <iostream>
#include <vector>
#include <algorithm>

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
    int ans = 64;
    for (auto i : a)
    {
        int cnt = 0;
        while (i % 2 == 0)
        {
            cnt++;
            i /= 2;
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}