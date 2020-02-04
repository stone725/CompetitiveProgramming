#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int min_doller;
    cin >> min_doller;
    int ans = -2 * 1e9;
    for (int i = 1; i < n; i++)
    {
        int doller;
        cin >> doller;
        ans = max(ans, doller - min_doller);
        min_doller = min(min_doller, doller);
    }
    cout << ans << "\n";
}