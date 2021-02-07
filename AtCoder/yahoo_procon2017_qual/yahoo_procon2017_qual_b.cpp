#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    sort(begin(a), end(a));
    cout << accumulate(begin(a), begin(a) + k, k * (k - 1ll) / 2) << "\n";
}