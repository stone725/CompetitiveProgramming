#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> a(n), b(n);
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int num;
        cin >> num;
        a[num - 1] = true;
    }
    int y;
    cin >> y;
    for (int i = 0; i < y; i++)
    {
        int num;
        cin >> num;
        b[num - 1] = true;
    }
    int ans = 0, z;
    cin >> z;
    for (int i = 0; i < z; i++)
    {
        int num;
        cin >> num;
        ans += !a[num - 1] || b[num - 1];
    }
    cout << ans << "\n";
}