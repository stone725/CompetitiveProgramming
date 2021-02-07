#include <iostream>

using namespace std;

int main()
{
    int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ma, da, mb, db;
    cin >> ma >> da;
    cin >> mb >> db;
    int ans = 0;
    for (int i = ma - 1; i < mb - 1; i++)
    {
        ans += month[i];
    }
    ans -= da;
    ans += db;
    cout << ans << "\n";
}