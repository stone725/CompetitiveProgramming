#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, n, m;
    cin >> a >> n >> m;
    int ans = 0;
    for (long long i = a; pow(i, n) <= m; i++)
    {
        long long score = 1;
        for (int j = 0; j < n; j++)
        {
            score *= i;
        }
        if (score == 0)
            continue;
        long long num = i - a;
        while (score)
        {
            num -= (score % 10);
            score /= 10;
        }
        ans += !num;
    }
    cout << ans << "\n";
}