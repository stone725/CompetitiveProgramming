#include <iostream>
#include <complex>

using namespace std;

int main()
{
    int k;
    cin >> k;
    const complex<double> p200(100, 100), p300(150, 150);
    int ans200 = 0, ans300 = 0;
    for (int i = 0; i < 300; i += k)
    {
        for (int j = 0; j < 300; j += k)
        {
            if (abs(p200 - complex<double>(i, j)) <= 100 && abs(p200 - complex<double>(i + k, j + k)) <= 100 && abs(p200 - complex<double>(i + k, j)) <= 100 && abs(p200 - complex<double>(i, j + k)) <= 100)
            {
                ans200++;
            }
            if (abs(p300 - complex<double>(i, j)) <= 150 && abs(p300 - complex<double>(i + k, j + k)) <= 150 && abs(p300 - complex<double>(i + k, j)) <= 150 && abs(p300 - complex<double>(i, j + k)) <= 150)
            {
                ans300++;
            }
        }
    }
    cout << ans200 << " " << ans300 << "\n";
}