#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    double avg = accumulate(begin(a), end(a), 0.) / n;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(avg - a[ans]) > abs(avg - a[i]))
        {
            ans = i;
        }
    }
    cout << ans << "\n";
}