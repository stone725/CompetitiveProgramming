#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int score = n + 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if (score > p)
        {
            ans++;
            score = p;
        }
    }
    cout << ans << "\n";
}