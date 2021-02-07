#include <iostream>
#include <utility>
#include <map>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    int ans = 0;
    for (auto i = m.rbegin(); i != m.rend() && i->first > 0; i++)
    {
        ans += i->second;
        if (k <= ans)
        {
            break;
        }
    }
    cout << ans << "\n";
}