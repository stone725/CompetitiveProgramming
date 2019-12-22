#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int a;
    cin >> a;
    cout << min(max(l, a), r);
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        cout << " " << min(max(l, a), r);
    }
    cout << "\n";
}