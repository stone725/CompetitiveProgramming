#include <iostream>

using namespace std;

int main()
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        ans += num;
    }
    cout << ans << "\n";
}