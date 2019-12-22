#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    long long num = accumulate(begin(a), end(a), a[0], gcd<long long, long long>);
    int ans = 0;
    for (long long i = 1; i * i <= num; i++)
    {
        if (num % i)
            continue;
        ans += 1 + (i * i < num);
    }
    cout << ans << "\n";
}