#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;
    long long ans = 1;
    if (n == 1)
    {
        cout << p << "\n";
        return 0;
    }
    for (int i = sqrt(p); i > 1; i--)
    {
        if (p % i)
            continue;
        long long score = p;
        bool check = true;
        for (int j = 0; j < n; j++)
        {
            if (score % i)
            {
                check = false;
                break;
            }
            score /= i;
        }
        if (check)
        {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}