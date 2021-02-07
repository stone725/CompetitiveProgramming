#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int r;
    cin >> r;
    cout << fixed << setprecision(20) << r * 2 * acos(-1.0) << "\n";
}