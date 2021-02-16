#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<complex<int>> p(n);
    for (auto &&i : p)
    {
        int real, imag;
        cin >> real >> imag;
        i = complex<int>(real, imag);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            complex<int> d = p[j] - p[i];
            if (abs(d.real()) >= abs(d.imag()))
            {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}