#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    set<int> s(begin(a), end(a));
    vector<int> b(begin(s), end(s));
    map<int, int> check;
    for (int i = 0; i < b.size(); i++)
    {
        check[b[i]] = i;
    }
    for (auto &&i : a)
    {
        cout << check[i] << "\n";
    }
}