#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        list<int> p(n);
        for (auto &&i : p)
        {
            cin >> i;
        }
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            check = is_sorted(begin(p), end(p)) || is_sorted(rbegin(p), rend(p));
            if (check)
            {
                break;
            }
            p.push_back(p.front());
            p.pop_front();
        }
        if (check)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}