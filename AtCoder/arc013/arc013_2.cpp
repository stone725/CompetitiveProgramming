#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int c;
    cin >> c;
    array<int, 3> item;
    array<int, 3> ans{0, 0, 0};
    for (int i = 0; i < c; i++)
    {
        for (auto &&j : item)
        {
            cin >> j;
        }
        sort(rbegin(item), rend(item));
        for (int j = 0; j < 3; j++)
        {
            ans[j] = max(ans[j], item[j]);
        }
    }
    cout << accumulate(begin(ans), end(ans), 1ll, multiplies<long long>()) << "\n";
}