#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long a, b, x;

long long calc(int n)
{
    return a * n + b * to_string(n).size();
}

int main()
{
    cin >> a >> b >> x;
    int s = 0, g = 1e9 + 1;
    while (g - s > 1)
    {
        int mid = (s + g) / 2;
        if (calc(mid) <= x)
        {
            s = mid;
        }
        else
        {
            g = mid;
        }
    }
    cout << s << "\n";
}