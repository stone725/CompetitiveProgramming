#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int t;
    cin >> t;
    while (t--)
    {
        cerr << str << "\n";
        int l, r, k;
        cin >> l >> r >> k;
        if (l == r)
            continue;
        l--;
        if (k > r - l)
        {
            k %= (r - l);
        }
        str = str.substr(0, l) + str.substr(r - k, k) + str.substr(l, r - l - k) + str.substr(r);
    }
    cout << str << "\n";
}