#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    sort(begin(a), end(a));
    if (a.back() < k)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (binary_search(begin(a), end(a), k))
    {
        cout << "POSSIBLE\n";
        return 0;
    }
    int score = a[1] - a[0];
    for (int i = 1; i + 1 < n; i++)
    {
        score = gcd(score, a[i + 1] - a[i]);
    }
    for (auto &&i : a)
    {
        if (i < k)
            continue;
        if ((k - i) % score == 0)
        {
            cout << "POSSIBLE\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}