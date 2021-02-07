#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    sort(rbegin(a), rend(a));
    if (a[0] < accumulate(begin(a) + 1, end(a), 0))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}