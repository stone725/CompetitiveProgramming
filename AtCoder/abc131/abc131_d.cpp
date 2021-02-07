#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> w(n);
    for (auto &&i : w)
    {
        cin >> i.second >> i.first;
    }
    sort(begin(w), end(w));
    long long now = 0;
    for (auto &&i : w)
    {
        now += i.second;
        if (i.first < now)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}