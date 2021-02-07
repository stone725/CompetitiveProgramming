#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> member(n);
    vector<int> a[3];
    for (auto &&i : member)
    {
        cin >> i.first >> i.second;
        i.second--;
        a[i.second].push_back(i.first);
    }
    for (auto &&i : a)
    {
        sort(begin(i), end(i));
    }
    for (auto &&i : member)
    {
        int win = 0, lose = 0, draw = -1;
        for (auto &&j : a)
        {
            win += lower_bound(begin(j), end(j), i.first) - begin(j);
            lose += end(j) - upper_bound(begin(j), end(j), i.first);
        }
        draw += upper_bound(begin(a[i.second]), end(a[i.second]), i.first) - lower_bound(begin(a[i.second]), end(a[i.second]), i.first);
        win += upper_bound(begin(a[(i.second + 1) % 3]), end(a[(i.second + 1) % 3]), i.first) - lower_bound(begin(a[(i.second + 1) % 3]), end(a[(i.second + 1) % 3]), i.first);
        lose += upper_bound(begin(a[(3 + i.second - 1) % 3]), end(a[(3 + i.second - 1) % 3]), i.first) - lower_bound(begin(a[(3 + i.second - 1) % 3]), end(a[(3 + i.second - 1) % 3]), i.first);
        cout << win << " " << lose << " " << draw << "\n";
    }
}