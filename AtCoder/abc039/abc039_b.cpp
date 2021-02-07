#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans;
    for (ans = 1; ans * ans * ans * ans < n; ans++)
        ;
    cout << ans << "\n";
}