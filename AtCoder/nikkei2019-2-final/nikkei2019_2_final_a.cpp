#include <iostream>
#include <vector>

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
    vector<int> b(n - 2);
    long long ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int num1 = 0;
        for (int j = 0; j < i; j++)
        {
            num1 += a[j] < a[i];
        }
        int num2 = 0;
        for (int j = i + 1; j < n; j++)
        {
            num2 += a[i] > a[j];
        }
        ans += num1 * num2;
    }
    cout << ans << "\n";
}