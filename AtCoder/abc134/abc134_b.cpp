#include <iostream>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int check = d * 2 + 1, ans = n / check + !!(n % check);
    cout << ans << "\n";
}