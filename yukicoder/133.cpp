#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int cnt = 0;
    double ans = 0;
    do
    {
        do
        {
            cnt++;
            int win = 0;
            for (int i = 0; i < n; i++)
            {
                win += b[i] < a[i];
            }
            ans += n < win * 2;
        } while (next_permutation(begin(b), end(b)));
    } while (next_permutation(begin(a), end(a)));
    ans /= cnt;
    cout << fixed << ans << "\n";
}