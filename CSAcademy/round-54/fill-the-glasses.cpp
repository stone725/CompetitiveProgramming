#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

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
    cout << accumulate(begin(a), begin(a) + k, 99) / 100 << "\n";
}