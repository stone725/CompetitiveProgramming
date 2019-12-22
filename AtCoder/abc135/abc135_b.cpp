#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &&i : p)
    {
        cin >> i;
    }
    if (is_sorted(begin(p), end(p)))
    {
        cout << "YES\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(p[i], p[j]);
            if (is_sorted(begin(p), end(p)))
            {
                cout << "YES\n";
                return 0;
            }
            swap(p[i], p[j]);
        }
    }
    cout << "NO\n";
}