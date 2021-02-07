#include <iostream>
#include <complex>

using namespace std;

int main()
{
    long double cx, cy, r;
    cin >> cx >> cy >> r;
    long double x[2], y[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> x[i] >> y[i];
        x[i] -= cx;
        y[i] -= cy;
    }
    int cnt = 0;
    bool check1 = false, check2 = false;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (x[i] * x[i] + y[j] * y[j] > r * r)
            {
                check2 = true;
                break;
            }
        }
    }

    if (x[0] <= -r && r <= x[1] && y[0] <= -r && r <= y[1])
    {
        check1 = false;
    }
    else
    {
        check1 = true;
    }
    if (check1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    if (check2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
