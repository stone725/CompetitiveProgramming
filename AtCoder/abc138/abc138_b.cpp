#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt += 1. / a;
    }
    cout << setprecision(12) << 1. / cnt << "\n";
}