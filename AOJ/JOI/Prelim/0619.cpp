#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int a[4], b[2];
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&j : b)
    {
        cin >> j;
    }
    sort(rbegin(a), rend(a));
    sort(rbegin(b), rend(b));
    cout << accumulate(begin(a), begin(a) + 3, 0) + b[0] << "\n";
}